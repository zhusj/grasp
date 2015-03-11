#!/usr/bin/env python

import sys 
import rospy

import math
import numpy
import time
import copy
import baxter_interface
from baxter_interface import CHECK_VERSION
import math
import tf

import std_msgs.msg
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)
from std_msgs.msg import Header
from sensor_msgs.msg import JointState
from object_recognition_msgs.msg import RecognizedObjectArray

from prx_decision_making.msg import DecisionMakingStateMessage
from prx_decision_making.msg import MotionPlanningStateMessage
from baxter_core_msgs.msg import EndpointState

from baxter_core_msgs.srv import (
    SolvePositionIK,
    SolvePositionIKRequest,
)

import moveit_commander
import moveit_msgs.msg
from moveit_commander import MoveGroupCommander, PlanningSceneInterface
from moveit_msgs.msg import PlanningScene, PlanningSceneComponents
from moveit_msgs.srv import GetPlanningScene

from prx_planning.srv import *

from dynamic_reconfigure.server import Server
from prx_mapping.cfg import prx_mappingConfig

import ast

import random


#RUN MODE
HARD_CODED_OBJECT = False

    
##############################################################################################
# Definitions                                                                                #
##############################################################################################

X_CLOSE_TO_OBJECT = 0.115
X_CLOSE_TO_OBJECT2 = 0.03
Z_CLOSE_TO_OBJECT = 0.03
X_ON_EDGE_OF_BIN = 0.7
X_APPROACH_STEP = 0.01

BAXTER_BASE_HIGH = 0.9
    

##############################################################################################
# Global variables initialization (not all need initialization)                              #
##############################################################################################

g_motion_planner_state_publisher = False

g_decision_making_state = False
g_decision_making_state_available = False

g_endpoint_state = False
g_endpoint_state_available = False

g_test_endpoint_state_available = False

g_shelf_on_the_scene = False
    
g_object_attached_to_the_gripper = False


##############################################################################################
# Support functions                                                                          #
##############################################################################################

def xfrange(start, stop, step):
    while start <= stop:
        yield start
        start += step
    return


def orientation_from_quaternion(quaternion):
    orientation = Quaternion()
    orientation.x = quaternion[0]
    orientation.y = quaternion[1]
    orientation.z = quaternion[2]
    orientation.w = quaternion[3]
    
    return orientation


def position_as_list(position):
    return [position.x, position.y, position.z]


def orientation_as_list(orientation):
    return [orientation.x, orientation.y, orientation.z, orientation.w]


def get_limb_postion_via_inverse_kinematics(endpoint_desired_state):
    global g_origin_robot_position # TODO: This should be the current arm configuration...
    
    ns = "ExternalTools/left/PositionKinematicsNode/IKService"
    iksvc = rospy.ServiceProxy(ns, SolvePositionIK)
    ikreq = SolvePositionIKRequest()
    hdr = Header(stamp = rospy.Time.now(), frame_id = 'base')
    
    pose = PoseStamped(hdr, endpoint_desired_state)
    ikreq.pose_stamp.append(pose)
    ikreq.seed_mode = 0 # SEED_AUTO = 0, SEED_CURRENT = 2, see http://sdk.rethinkrobotics.com/wiki/API_Reference#Inverse_Kinematics_Solver_Service
    js = JointState()
    js.header = hdr
    js.name = g_origin_robot_position.keys()
    js.position = g_origin_robot_position.values()
    ikreq.seed_angles.append(js)
    # print ikreq
    try:
        rospy.wait_for_service(ns, 5.0)
        resp = iksvc(ikreq)
    except (rospy.ServiceException, rospy.ROSException), e:
        rospy.logerr("######### Service call failed: %s" % (e,))
        sys.exit(0)
    if (resp.isValid[0]):
        limb_joints = dict(zip(resp.joints[0].name, resp.joints[0].position))
    else:
        print("Could not find IK for given pose in get_limb_postion_via_inverse_kinematics()")
        limb_joints = False
    
    return limb_joints


def plan_and_move_to_joints_configuration(joints_configuration):
    global g_move_group

    print "plan_and_move_to_joints_configuration()"
    for tries in range(1, 10):
        g_move_group.clear_pose_targets()
        g_move_group.set_start_state_to_current_state()
        g_move_group.set_joint_value_target(joints_configuration)
        plan = g_move_group.plan()
        if not plan.joint_trajectory.points:
            if tries == 9:
                print "@@@@@@@@@@@@@ Failed 9 times..."
                return False
            else:
                print "Failed to go to target joints configuration no. ", tries
                
                continue
        print "We have a plan to go to a specific joints configuration!"
        g = g_move_group.go(wait=True)
        if g:
            print "Joints configuration achieved OKKKKK!!!"
            return True
    
    return False


def new_plan_and_move_end_effector_to(end_effector_pose):
    global g_move_group

    print "plan_and_move_end_effector_to(end_effector_pose)"
    for tries in range(1, 10):
        g_move_group.clear_pose_targets()
        g_move_group.set_start_state_to_current_state()
        g_move_group.set_joint_value_target(end_effector_pose)
        plan = g_move_group.plan()
        if not plan.joint_trajectory.points:
            if tries == 9:
                print "@@@@@@@@@@@@@ Failed 9 times..."
                return False
            else:
                print "Failed to go to target joints configuration no. ", tries
                
                continue
        print "We have a plan to go to a specific end effector pose!"
        g = g_move_group.go(wait=True)
        if g:
            print "End effector pose achieved OKKKKK!!!"
            return True
    
    return False


def plan_and_move_end_effector_to(end_effector_pose):
    global g_move_group

    local_end_effector_pose = copy.deepcopy(end_effector_pose)
    print "plan_and_move_end_effector_to():"
    print "= end_effector_pose:"
    print local_end_effector_pose
    for tries in range(1, 10):
        limb_joints = get_limb_postion_via_inverse_kinematics(local_end_effector_pose)
        if limb_joints == False:
            if tries == 9:
                print "@@@@@@@@@@@@@ Failed 9 times..."
                return False
            else:
                print "Failed to find IK to go to target end effector pose no. ", tries
                local_end_effector_pose.position.z += 0.01 * (random.random() - 0.5)
                continue
        else:
            break
    return plan_and_move_to_joints_configuration(limb_joints)

    # The code below is not working... TODO: Examine why in move_group.py
#     g_move_group.clear_pose_targets()
#     end_effector_pose_stamped = PoseStamped()
#     end_effector_pose_stamped.header.frame_id = g_move_group.get_planning_frame()
#     end_effector_pose_stamped.header.stamp = rospy.Time.now() 
#     end_effector_pose_stamped.pose = end_effector_pose
#     print "In plan_and_move_end_effector_to()"
#     print "= Planning reference frame: %s" % g_move_group.get_planning_frame()
#     print "= End effector link: %s" % g_move_group.get_end_effector_link()
#     print "= end_effector_pose_stamped:"
#     print end_effector_pose_stamped
# 
#     g_move_group.set_pose_target(end_effector_pose_stamped)
#     for tries in range(1, 10):
#         try:
#             g_move_group.plan()
#         except:
#             if tries == 9:
#                 print "@@@@@@@@@@@@@ Failed 9 times..."
#                 return False
#             else:
#                 print "Failed to plan to get end effector to target pose"
#                 continue
#         print "Have a plan. Now lets try to move"
#         g = g_move_group.go(wait=True)
#         if g:
#             print "End effector pose achieved OKKKKK!!!!!!"
#             return True
#     
#     return False


def get_tf_transform(from_frame, to_frame):
    tf_listener = tf.TransformListener()
    
    for i in range(0, 10):
        joy = True
        try:
            (trans,rot) = tf_listener.lookupTransform(from_frame, to_frame, rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            joy = False
        print "tf_listener.lookupTransform('" + from_frame + "', '" + to_frame + "', rospy.Time(0)) failed..."
        if joy == False and i == 9:
            print "Nothing listened to after 9 tries..."
            return False
        elif joy == True:
            break
        rospy.sleep(0.5)

    transform = Pose()
    transform.position.x = trans[0]
    transform.position.y = trans[1]
    transform.position.z = trans[2]
    transform.orientation.x = rot[0]
    transform.orientation.y = rot[1]
    transform.orientation.z = rot[2]
    transform.orientation.w = rot[3]
    
    return transform


def get_object_pose():
    global g_shelf_description
    
    object_pose = Pose()
    if HARD_CODED_OBJECT == True:
        object_pose.position.x = 1.03316833124 #trans[0]
        object_pose.position.y = 0.55459452847 #trans[1]
        object_pose.position.z = 0.288401514479 #trans[2]
        object_pose.orientation.x = -0.477072525368 #rot[0]
        object_pose.orientation.y = 0.534384847975 #rot[1]
        object_pose.orientation.z = -0.488505960788 #rot[2]
        object_pose.orientation.w = 0.498193301911 #rot[3]
        return object_pose
    
    for i in range(0, 10):
        object_pose = get_tf_transform('/base', '/object_frame')
        if object_pose != False:
           if object_pose.position.x < g_shelf_description.x:
	       print "======= Object detected outside (in front) of the bin"
	       print "object_pose.position.x = ", object_pose.position.x, "   g_shelf_description.x ", g_shelf_description.x
           else:
               return object_pose
    return False


def rotate_orientation_quaternion(orientation):
    global first_rotating_axis
    global first_rotating_axis_signal
    global second_rotating_axis
    global second_rotating_axis_signal

    rotation1 = tf.transformations.quaternion_from_euler(0.0, 0.0, 0.0)
    rotation2 = tf.transformations.quaternion_from_euler(0.0, 0.0, 0.0)
    theta = math.pi / 2.0
    if first_rotating_axis == 1:
        rotation1 = tf.transformations.quaternion_from_euler(first_rotating_axis_signal * theta, 0.0, 0.0)
    elif first_rotating_axis == 2:
        rotation1 = tf.transformations.quaternion_from_euler(0.0, first_rotating_axis_signal * theta, 0.0)
    elif first_rotating_axis == 3:
        rotation1 = tf.transformations.quaternion_from_euler(0.0, 0.0, first_rotating_axis_signal * theta)

    if second_rotating_axis == 1:
        rotation2 = tf.transformations.quaternion_from_euler(second_rotating_axis_signal * theta, 0.0, 0.0)
    elif second_rotating_axis == 2:
        rotation2 = tf.transformations.quaternion_from_euler(0.0, second_rotating_axis_signal * theta, 0.0)
    elif second_rotating_axis == 3:
        rotation2 = tf.transformations.quaternion_from_euler(0.0, 0.0, second_rotating_axis_signal * theta)

    _orientation = copy.deepcopy(rotation1) # just to allocate this variable
    _orientation[0] = orientation.x
    _orientation[1] = orientation.y
    _orientation[2] = orientation.z
    _orientation[3] = orientation.w
    #print "rotation1 ========== ", rotation1
    new_orientation = tf.transformations.quaternion_multiply(_orientation, rotation1)
    #print "rotation2 ========== ", rotation2
    new_orientation = tf.transformations.quaternion_multiply(new_orientation, rotation2)
    #print first_rotating_axis, second_rotating_axis, first_rotating_axis_signal, second_rotating_axis_signal
    orientation_rotated = Quaternion()
    orientation_rotated.x = new_orientation[0]
    orientation_rotated.y = new_orientation[1]
    orientation_rotated.z = new_orientation[2]
    orientation_rotated.w = new_orientation[3]

    return orientation_rotated


def rotate_orientation(orientation, rotation):
    _orientation = numpy.empty((4, ), dtype=numpy.float64)
    _orientation[0] = orientation.x
    _orientation[1] = orientation.y
    _orientation[2] = orientation.z
    _orientation[3] = orientation.w

    _rotation = numpy.empty((4, ), dtype=numpy.float64)
    _rotation[0] = rotation.x
    _rotation[1] = rotation.y
    _rotation[2] = rotation.z
    _rotation[3] = rotation.w
    #print "rotation1 ========== ", rotation1
    new_orientation = tf.transformations.quaternion_multiply(_orientation, _rotation)
    #print "rotation2 ========== ", rotation2
    orientation_rotated = Quaternion()
    orientation_rotated.x = new_orientation[0]
    orientation_rotated.y = new_orientation[1]
    orientation_rotated.z = new_orientation[2]
    orientation_rotated.w = new_orientation[3]

    return orientation_rotated


def add_shelf_to_scene():
    global g_scene
    global g_shelf_on_the_scene
    global g_shelf_description
    
    if g_shelf_on_the_scene == False:
        print "== Adding shelf to the scene"
        shelf_pose = PoseStamped()
        shelf_pose.header = Header(stamp = rospy.Time.now(), frame_id = '/base')
        shelf_pose.pose.position.x = g_shelf_description.x + g_shelf_description.depth / 2.0 # see shelf_description.txt
        shelf_pose.pose.position.y = g_shelf_description.y
        shelf_pose.pose.position.z = g_shelf_description.z + g_shelf_description.height / 2.0 # see shelf_description.txt
        shelf_orientation = tf.transformations.quaternion_from_euler(
            g_shelf_description.roll * math.pi / 180.0, 
            g_shelf_description.pitch * math.pi / 180.0, 
            g_shelf_description.yaw * math.pi / 180.0)
        shelf_pose.pose.orientation = orientation_from_quaternion(shelf_orientation)
        g_scene.add_box("shelf", shelf_pose, (g_shelf_description.depth, g_shelf_description.width, g_shelf_description.height)) # delete the previous octomap

        rospy.sleep(3.0)
        g_shelf_on_the_scene = True
    
    return


def remove_shelf_from_the_scene():
    global g_scene
    global g_shelf_on_the_scene
    
    print "== Removing shelf from the scene"
    header = Header(stamp = rospy.Time.now(), frame_id = '/base')
    g_scene.remove_world_object2("shelf", header)
    g_shelf_on_the_scene = False
    
    return
    

##############################################################################################
# Motion functions                                                                           #
##############################################################################################

def move_closer_to_object():
    global g_object_pose
    global g_endpoint_state
    global g_motion_planner_state_publisher

    if g_object_pose != False:
        pose_close_to_object = copy.deepcopy(g_object_pose)
        pose_close_to_object.orientation = g_endpoint_state.pose.orientation
        pose_close_to_object.position.x = g_object_pose.position.x - X_CLOSE_TO_OBJECT # stop close to the object
        move_ok = plan_and_move_end_effector_to(pose_close_to_object)
    
        if move_ok:
            state = 4 # robot is close to object
        else:
            print "######### Could not approach for grasping..."
            header = Header(stamp = rospy.Time.now(), frame_id = '/base')
            g_scene.remove_world_object2(g_decision_making_state.object_name, header)
            state = 8 # robot fail to get close to object
    else:
        print "######### No object detected."
        state = 8 # robot fail to get close to object -> send state machine back to move to Bin

    header = Header(stamp = rospy.Time.now(), frame_id = '/base')
    g_motion_planner_state_publisher.publish(header, state)
    rospy.sleep(5.0) # Alberto: Critical time. If too small (i.e. 2.0), end effector does not reach object correctly. 
    print "################ New end effector pose:"
    print g_endpoint_state.pose
    
    return state


def attach_object_to_the_gripper():
    global g_object_pose
    global g_object_attached_to_the_gripper
    
    if g_object_attached_to_the_gripper == False:
        attaching_pose_in_gripper = PoseStamped()
        attaching_pose_in_gripper.header = Header(stamp = rospy.Time.now(), frame_id = 'left_gripper')
        attaching_pose_in_gripper.pose.position = Point(*[0.0, 0.0, 0.06]) # TODO: This constant is object dependent
        
        gripper_pose_with_respect_to_base = get_tf_transform('/base', '/left_gripper')
        attaching_pose_in_gripper.pose.orientation = rotate_orientation(gripper_pose_with_respect_to_base.orientation, rotate_orientation_quaternion(g_object_pose.orientation))
        print "Attaching the object mesh to the gripper"
        g_scene.attach_mesh("left_gripper", g_decision_making_state.object_name + '_attached', attaching_pose_in_gripper, g_decision_making_state.object_name + ".stl", (1,1,1), ['left_gripper_base', 'left_gripper'])
        g_object_attached_to_the_gripper = True
    
    rospy.sleep(0.8)
    
    return
        

def dettach_object_from_the_gripper():
    global g_object_attached_to_the_gripper
    global g_decision_making_state
    
    if g_object_attached_to_the_gripper == True:
        g_scene.remove_attached_object("left_gripper", g_decision_making_state.object_name + '_attached')
        header = Header(stamp = rospy.Time.now(), frame_id = '/base')
        g_scene.remove_world_object2(g_decision_making_state.object_name + '_attached', header)
        g_object_attached_to_the_gripper = False
        
    return

        
def grasp():
    global g_left_gripper
    global g_object_pose
    global g_endpoint_state
    global g_motion_planner_state_publisher

    print "Removing the object mesh from the scene"
    header = Header(stamp = rospy.Time.now(), frame_id = '/base')
    g_scene.remove_world_object2(g_decision_making_state.object_name, header)

    g_left_gripper.open()
    rospy.sleep(0.8)

    object_grasp_pose = copy.deepcopy(g_object_pose)
    object_grasp_pose.orientation = g_endpoint_state.pose.orientation
    object_grasp_pose.position.x = g_object_pose.position.x - X_CLOSE_TO_OBJECT2 # grasp pose

    move_ok = plan_and_move_end_effector_to(object_grasp_pose)
    
    if move_ok == True:
        g_left_gripper.close() # grasp!
        attach_object_to_the_gripper()
        print "################ GRASPED!!"
        
        # Move the object up
        object_grasp_pose.position.z = object_grasp_pose.position.z + Z_CLOSE_TO_OBJECT 
        print "################ Object pose + Z_CLOSE_TO_OBJECT:"
        print object_grasp_pose
        print "Try and raise the object"
        move_ok = plan_and_move_end_effector_to(object_grasp_pose)
        if move_ok == True:
            state = 7 # grasped and raised
        else:
            print "######### Could not raise"
            g_left_gripper.open()
            dettach_object_from_the_gripper()
            state = 8 # robot fail to move the object up
    else:
        print "######### Could not grasp"
        state = 8 # robot fail to get close to object
    
    header = Header(stamp = rospy.Time.now(), frame_id = '/base')
    g_motion_planner_state_publisher.publish(header, state)
    rospy.sleep(3.0)
    
    return state
    

def move_away_from_bin():
    global g_object_pose
    global g_endpoint_state
    global g_motion_planner_state_publisher
    global g_shelf_description
    
    x_origin = g_shelf_description.x - 0.15 # TODO: this constant should be a define

    pose_away_from_bin = copy.deepcopy(g_object_pose)
    pose_away_from_bin.orientation = g_endpoint_state.pose.orientation
    pose_away_from_bin.position.x = x_origin 
    print "################ End effector pose outside of the bin:"
    print pose_away_from_bin
    print "Try and retract the end effector with the object outside of the bin"
    move_ok = plan_and_move_end_effector_to(pose_away_from_bin)
    if move_ok:
        rospy.sleep(0.8)
        print "########### Successfully grasped and retracted outside of bin"
        state = 5 # moved away from bin
    else:
        rospy.sleep(0.8)
        print "######### Could not retract #"
        g_left_gripper.open()
        dettach_object_from_the_gripper()
        state = 8 # robot fail to move the object up

    header = Header(stamp = rospy.Time.now(), frame_id = '/base')
    g_motion_planner_state_publisher.publish(header, state)
    rospy.sleep(0.8)

    return state


def clear_octomap():
    global g_scene_publisher

    print "== Clear octomap"
    rospy.wait_for_service('/get_planning_scene', 5.0)
    get_planning_scene = rospy.ServiceProxy('/get_planning_scene', GetPlanningScene)
    request = PlanningSceneComponents(components=PlanningSceneComponents.ALLOWED_COLLISION_MATRIX)
    response = get_planning_scene(request)
    acm = response.scene.allowed_collision_matrix
    
    # We just publish a scene diff without any difference. 
    # A hack in planning_scene_monitor.cpp clear the octomap if the shelf cuboid is or was recently in the scene.
    planning_scene_diff = PlanningScene(is_diff=True, allowed_collision_matrix=acm)
    g_scene_publisher.publish(planning_scene_diff)
    rospy.sleep(1.0)    
    
    return


##############################################################################################
# Main operating function                                                                    #
##############################################################################################

def motion_planner():
    global g_decision_making_state
    global g_decision_making_state_available
    global g_motion_planner_state_publisher
    global g_left_gripper
    global g_to_order_bin_robot_position
    global g_object_pose
    global g_bin_positions
 
    if g_decision_making_state_available == True:
        state = 0 # none
        current_motion_planning_mode = g_decision_making_state.motion_planning_mode

        if current_motion_planning_mode == 6: # mp_to_O -> move to origin
            print "============== Moving to origin =============="
            add_shelf_to_scene()
            
            print g_decision_making_state.bin_id
            print g_bin_positions[g_decision_making_state.bin_id]['origin_robot_position']
            plan_and_move_end_effector_to(g_bin_positions[g_decision_making_state.bin_id]['origin_robot_position'])
            
            g_left_gripper.close()
            
            state = 1 # robot is at the origin
            header = Header(stamp = rospy.Time.now(), frame_id = '/base')
            g_motion_planner_state_publisher.publish(header, state)
            rospy.sleep(0.8)

        if current_motion_planning_mode == 7: # mp_to_B -> move to Bin
            print "============== Moving to bin =============="
            print g_decision_making_state.bin_id
            # print g_bin_positions[g_decision_making_state.bin_id]['bin_robot_position']
            # plan_and_move_end_effector_to(g_bin_positions[g_decision_making_state.bin_id]['bin_robot_position'])
            print g_bin_positions[g_decision_making_state.bin_id]['map_robot_position_2']
            plan_and_move_end_effector_to(g_bin_positions[g_decision_making_state.bin_id]['map_robot_position_2'])
            add_shelf_to_scene()    
            rospy.sleep(2.0)
            clear_octomap()
            
            state = 2 # robot is at the bin
            header = Header(stamp = rospy.Time.now(), frame_id = '/base')
            g_motion_planner_state_publisher.publish(header, state)
            rospy.sleep(0.8)

        if current_motion_planning_mode == 8: # mp_to_M -> move to map
            print "============== Moving to map =============="
            rospy.sleep(2.0)
            print "Removing shelf model"
            remove_shelf_from_the_scene()
            print "Shelf model removed"
            
            # plan_and_move_end_effector_to(g_bin_positions[g_decision_making_state.bin_id]['map_robot_position_1'])
            # rospy.sleep(1.0)
            # plan_and_move_end_effector_to(g_bin_positions[g_decision_making_state.bin_id]['map_robot_position_2'])
	    
            print "Get object pose"
            g_object_pose = get_object_pose()
            print "################ Object pose:"
            print g_object_pose
            if g_object_pose != False:
                object_mesh_pose = PoseStamped()
                object_mesh_pose.header = Header(stamp = rospy.Time.now(), frame_id = '/base')
                object_mesh_pose.pose = g_object_pose
                object_mesh_pose.pose.orientation = rotate_orientation_quaternion(object_mesh_pose.pose.orientation)
                print "Adding the object mesh to the scene"  
                g_scene.add_mesh(g_decision_making_state.object_name, object_mesh_pose, g_decision_making_state.object_name + ".stl")
                print "Object model added"
                rospy.sleep(2.0)

            state = 3 # bin mapped
            header = Header(stamp = rospy.Time.now(), frame_id = '/base')
            g_motion_planner_state_publisher.publish(header, state)
            rospy.sleep(0.8)

        if current_motion_planning_mode == 9: # mp_to_Ob_ -> move closer to object
            print "============== Moving close to object =============="
            state = move_closer_to_object()

        if current_motion_planning_mode == 12: # grasp -> grasp move
            print "============== Grasping =============="
            state = grasp()
    
        if current_motion_planning_mode == 10: # mp_to_AB_ -> move away from bin
            print "============== Moving away from bin =============="
            state = move_away_from_bin()

        if current_motion_planning_mode == 11: # mp_to_OB -> move to order bin
            print "============== Moving to order bin =============="
            add_shelf_to_scene()

            plan_and_move_to_joints_configuration(g_to_order_bin_robot_position)
            rospy.sleep(0.5)
            g_left_gripper.open()
            dettach_object_from_the_gripper()

            state = 6 # robot is at the order bin
            header = Header(stamp = rospy.Time.now(), frame_id = '/base')
            g_motion_planner_state_publisher.publish(header, state)
            rospy.sleep(0.8)
             
        # print "motion planner new state = ", state, "decision making state = ", g_decision_making_state.state, "current motion planning mode = ", current_motion_planning_mode
        rospy.sleep(0.5)
        g_decision_making_state_available = False

    return
    

##############################################################################################
# Handlers                                                                                   #
##############################################################################################

def decision_making_state_handler(data):
    global g_decision_making_state
    global g_decision_making_state_available
    global g_tf_transform_broadcaster
    global g_bin_positions

    g_decision_making_state = data
    g_decision_making_state.bin_id = chr(g_decision_making_state.bin_id)
    g_decision_making_state_available = True

    # Publish objec_pose_hit tf transform
    position = position_as_list(g_bin_positions[g_decision_making_state.bin_id]['object_pose_hint'].position)
    orientation = orientation_as_list(g_bin_positions[g_decision_making_state.bin_id]['object_pose_hint'].orientation)
    g_tf_transform_broadcaster.sendTransform(position, orientation, rospy.Time.now(), "/object_pose_hint", "/base")

    return

    
def endpoint_state_state_handler(data):
    global g_endpoint_state
    global g_endpoint_state_available

    g_endpoint_state = data
    g_endpoint_state_available = True
    
    return
    
    
def detected_object_handler(data):
    global g_detected_object_array
    
    g_detected_object_array = data
    #print g_detected_object_array.objects[0].confidence
    #print g_detected_object_array.objects[0].bounding_mesh.vertices[0]
    #print g_detected_object_array.objects[0].point_clouds[0]
    
    return


def reconfigure_callback(config, level):
    global first_rotating_axis
    global first_rotating_axis_signal
    global second_rotating_axis
    global second_rotating_axis_signal
    
    first_rotating_axis = config.first_rotating_axis
    second_rotating_axis = config.second_rotating_axis
    first_rotating_axis_signal = config.first_rotating_axis_signal
    second_rotating_axis_signal = config.second_rotating_axis_signal
    
    print "==== Rotations updated"
    print first_rotating_axis, second_rotating_axis, first_rotating_axis_signal, second_rotating_axis_signal
    
    return config
    

##############################################################################################
# Initializations                                                                            #
##############################################################################################

class ShelfDescription(object):
    def __init__(self, initial_data):
       for key in initial_data:
           setattr(self, key, initial_data[key])
    
    def __str__(self):
        return "{'x':%s, 'y':%s, 'z':%s, 'roll':%s, 'pitch':%s, 'yaw':%s, 'width':%s, 'height':%s, 'rows':%s, 'cols':%s}"  % (self.x, self.y, self.z, self.roll, self.pitch, self.yaw, self.width, self.height, self.rows, self.cols)
    

def init_shelf_parameters():  
    global g_shelf_description

    f = open('shelf_description.txt', 'r')
    str_desc = f.readline()
    g_shelf_description = ShelfDescription(ast.literal_eval(str_desc))
    f.close()
    print g_shelf_description

    return


def compute_scene_poses():
    global g_bin_positions
    global g_shelf_description
    
    g_bin_positions = {}
    x_origin = g_shelf_description.x - 0.15
    x_mapping = g_shelf_description.x - 0.30
    bin_width = g_shelf_description.width / g_shelf_description.cols
    bin_height = g_shelf_description.height / g_shelf_description.rows
    for bin in 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L':
        g_bin_positions[bin] = {}
        pose = Pose()
        pose.position.x = x_origin
        pose.position.y = g_shelf_description.y
        pose.position.z = g_shelf_description.z + g_shelf_description.height / 2.0
        pose.orientation.x = math.sqrt(0.5)
        pose.orientation.y = 0.0
        pose.orientation.z = math.sqrt(0.5)
        pose.orientation.w = 0.0
        g_bin_positions[bin]['origin_robot_position'] = pose
        
        i = ord(bin) - ord('A')
        x_index = i % g_shelf_description.cols
        y_index = i // g_shelf_description.cols
        pose_i = copy.deepcopy(pose)
        pose_i.position.x = x_mapping
        pose_i.position.y = g_shelf_description.y - (x_index * bin_width - bin_width)
        pose_i.position.z = (g_shelf_description.rows - y_index) * bin_height - (bin_height / 2.0) + g_shelf_description.z
        g_bin_positions[bin]['bin_robot_position'] = pose_i

        pose_j = copy.deepcopy(pose_i)
        g_bin_positions[bin]['map_robot_position_1'] = pose_j

        pose_k = copy.deepcopy(pose_i)
        pose_k.position.z -= 0.05
        g_bin_positions[bin]['map_robot_position_2'] = pose_k

        pose_l = copy.deepcopy(pose_i)
        pose_l.position.x = g_shelf_description.x + g_shelf_description.depth / 2.0
        g_bin_positions[bin]['object_pose_hint'] = pose_l
    return


def motion_planner_int():
    global g_origin_robot_position
    global g_to_order_bin_robot_position
    global g_tf_transform_broadcaster

    g_origin_robot_position = {'left_w0': -2.3285828333496097, 'left_w1': 1.0131943092407227, 'left_w2': 1.523242920629883, 'left_e0': -0.9506845922058106, 'left_e1': 2.2495828228637698, 'left_s0': 0.6201117327941895, 'left_s1': 0.5553010445800781}
    g_to_order_bin_robot_position = {'left_w0': -1.191136080432129, 'left_w1': -1.4415584437683107, 'left_w2': 0.5204029816955567, 'left_e0': -1.7924565485961916, 'left_e1': 0.8877913799743653, 'left_s0': 0.6975777624938966, 'left_s1': 0.34476218168334966} 

    init_shelf_parameters()
    compute_scene_poses()
    g_tf_transform_broadcaster = tf.TransformBroadcaster()
    
    return


def motion_planner_main():
    global g_motion_planner_state_publisher
    global g_left_gripper
    global g_scene
    global g_move_group
    global g_scene_publisher
  
    rospy.init_node('motion_planner', anonymous=True)
    moveit_commander.roscpp_initialize(sys.argv)

    # Initializations
    motion_planner_int()
    
    # Subscribers
    rospy.Subscriber("/decision_making_state", DecisionMakingStateMessage, decision_making_state_handler)
    rospy.Subscriber("/robot/limb/left/endpoint_state", EndpointState, endpoint_state_state_handler)
    rospy.Subscriber("/recognized_object_array", RecognizedObjectArray, detected_object_handler)
    srv = Server(prx_mappingConfig, reconfigure_callback)

    # Publishers
    g_motion_planner_state_publisher = rospy.Publisher('/motion_planner_state', MotionPlanningStateMessage, queue_size=1)
    g_scene_publisher = rospy.Publisher('planning_scene', PlanningScene, queue_size = 10)

    # MoveIt!
    g_scene = moveit_commander.PlanningSceneInterface()
    robot = moveit_commander.RobotCommander()
    g_move_group = moveit_commander.MoveGroupCommander("left_arm")
    
    # Enable robot
    rs = baxter_interface.RobotEnable(CHECK_VERSION)
    rs.enable()
    
    # Set and calibrate gripper
    g_left_gripper = baxter_interface.Gripper('left')
    if g_left_gripper.error():
        g_left_gripper.reset()
    if (not g_left_gripper.calibrated() and g_left_gripper.type() != 'custom'):
        g_left_gripper.calibrate()
    
    # Main loop
    rate = rospy.Rate(5) # hz
    while not rospy.is_shutdown():
        motion_planner()
        rate.sleep()

    return


if __name__ == '__main__':
    motion_planner_main()
