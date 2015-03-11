#!/usr/bin/env python
# Software License Agreement (BSD License)
#
# Copyright (c) 2008, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of Willow Garage, Inc. nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Revision $Id$

import sys 
import rospy
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

from prx_decision_making.msg import DecisionMakingStateMessage
from prx_decision_making.msg import MotionPlanningStateMessage
from baxter_core_msgs.msg import EndpointState
 
from baxter_core_msgs.srv import (
    SolvePositionIK,
    SolvePositionIKRequest,
)

#RUN MODE
HARD_CODED_OBJECT = False

# Definitions
X_CLOSE_TO_OBJECT = 0.085
X_CLOSE_TO_OBJECT2 = 0.02
Z_CLOSE_TO_OBJECT = 0.03
X_ON_EDGE_OF_BIN = 0.8
X_APPROACH_STEP = 0.05

# Global variables initialization (not all need initialization)
g_motion_planner_state_publisher = False

g_decision_making_state = False
g_decision_making_state_available = False

g_endpoint_state = False
g_endpoint_state_available = False

g_test_endpoint_state_available = False


def xfrange(start, stop, step):
    while start <= stop:
        yield start
        start += step
    return


def workspace_interpolate(object_pose_start,object_pose_end,interpolation_step):
    global g_limb
    
    delx = object_pose_start.position.x - object_pose_end.position.x
    dely = object_pose_start.position.y - object_pose_end.position.y
    delz = object_pose_start.position.z - object_pose_end.position.z
    distance = math.sqrt(delx * delx + dely * dely + delz * delz)
    if (distance == 0):
        return True
        
    parameter_step = 1 / float(distance / float(interpolation_step))    
    interpolate_pose = copy.deepcopy(object_pose_start)    

    for i in xfrange(0,1,parameter_step):
        interpolate_pose.position.x = object_pose_start.position.x-(delx*i)
        interpolate_pose.position.y = object_pose_start.position.y-(dely*i)
        interpolate_pose.position.z = object_pose_start.position.z-(delz*i)
        print "######### Pose interpolated"
        print interpolate_pose
        limb_joints = get_limb_postion_via_inverse_kinematics(interpolate_pose)
        if limb_joints != False:
            g_limb.move_to_joint_positions(limb_joints)
            print "######### Just moved to IK computed joints pose!!!"
        else:
            print "######### Could not find limb joints pose."
            return False
    
    return True


def get_limb_postion_via_inverse_kinematics(endpoint_desired_state):
    global g_origin_robot_position
    
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
        print("######### INVALID POSE - No Valid Joint Solution Found.")
        limb_joints = False
    
    return limb_joints


def get_object_pose():
    global g_tf_listener
    
    if HARD_CODED_OBJECT == True:
        object_pose = Pose()
        object_pose.position.x = 1.03316833124 #trans[0]
        object_pose.position.y = 0.55459452847 #trans[1]
        object_pose.position.z = 0.288401514479 #trans[2]
        object_pose.orientation.x = -0.477072525368 #rot[0]
        object_pose.orientation.y = 0.534384847975 #rot[1]
        object_pose.orientation.z = -0.488505960788 #rot[2]
        object_pose.orientation.w = 0.498193301911 #rot[3]
        return object_pose
    for i in range(0, 20):
        joy = True
        try:
            (trans,rot) = g_tf_listener.lookupTransform('/base', '/object_frame', rospy.Time(0))
        except (tf.LookupException, tf.ConnectivityException, tf.ExtrapolationException):
            joy = False
        print "g_tf_listener.lookupTransform('/base', '/object_frame', rospy.Time(0)) failed..."
        if joy == False and i == 19:
            print "Nothing listened to"
            return False
        elif joy == True:
            break
        rospy.sleep(0.5)
    object_pose = Pose()
    object_pose.position.x = trans[0]
    object_pose.position.y = trans[1]
    object_pose.position.z = trans[2]
    object_pose.orientation.x = rot[0]
    object_pose.orientation.y = rot[1]
    object_pose.orientation.z = rot[2]
    object_pose.orientation.w = rot[3]
    
    return object_pose
    
    
def move_closer_to_object():
    global g_object_pose
    global g_endpoint_state
    global g_motion_planner_state_publisher

    print "################ APPROACH POSE BEFORE GRASP:"
    g_object_pose = get_object_pose()
    print "################ Object pose:"
    print g_object_pose
    if g_object_pose != False:
        g_object_pose.orientation = g_endpoint_state.pose.orientation # TODO: Alberto: get object orientation via object detection module
        
        object_pose_start = copy.deepcopy(g_object_pose)
        object_pose_end = copy.deepcopy(g_object_pose)
        object_pose_end.position.x = g_object_pose.position.x - X_CLOSE_TO_OBJECT # stop close to the object
        object_pose_start.position.x = X_ON_EDGE_OF_BIN
        if object_pose_start.position.x >= object_pose_end.position.x:
            object_pose_start.position.x = object_pose_end.position.x

        grasp_interpolate = workspace_interpolate(object_pose_start, object_pose_end, X_APPROACH_STEP*3)
    
        if grasp_interpolate != False:
            state = 4 # robot is close to object
        else:
            print "######### Could not find limb joints pose."
            state = 8 # robot fail to get close to object
    else:
        print "######### No object detected."
        state = 8 # robot fail to get close to object -> send state machine back to move to Bin

    header = std_msgs.msg.Header()
    g_motion_planner_state_publisher.publish(header, state)
    rospy.sleep(5.0) # Alberto: Critical time. If too small (i.e. 2.0), end effector does not reach object correctly. 
    print "################ End effector pose:"
    print g_endpoint_state.pose
    
    return state
    
    
def grasp():
    global g_left_gripper
    global g_object_pose
    global g_motion_planner_state_publisher

    g_left_gripper.open()
    rospy.sleep(0.8)

    object_pose_start = copy.deepcopy(g_object_pose)
    object_pose_end = copy.deepcopy(g_object_pose)
    object_pose_end.position.x = g_object_pose.position.x - X_CLOSE_TO_OBJECT2 # grasp pose
    object_pose_start.position.x = g_object_pose.position.x - X_CLOSE_TO_OBJECT # approach end pose
    print "################ Object pose 2:"
    print g_object_pose

    grasp_interpolate = workspace_interpolate(object_pose_start, object_pose_end, X_APPROACH_STEP)
    
    if grasp_interpolate != False:
        g_left_gripper.close() # grasp!
        rospy.sleep(0.8)
        print "################ GRASPED!!"
        object_pose_start = copy.deepcopy(object_pose_end)
        object_pose_end.position.z = object_pose_end.position.z + Z_CLOSE_TO_OBJECT # move the object up
        print "################ Object pose + Z_CLOSE_TO_OBJECT:"
        print object_pose_end
        grasp_raise_interpolate = workspace_interpolate(object_pose_start, object_pose_end, X_APPROACH_STEP * 2)
        if grasp_raise_interpolate != False:
            rospy.sleep(0.8)
            object_pose_start=copy.deepcopy(object_pose_end)
            object_pose_end.position.x = X_ON_EDGE_OF_BIN # move the object up
            print "################ Object pose retracted out of bin:"
            print object_pose_end
            grasp_retract_interpolate=workspace_interpolate(object_pose_start,object_pose_end,X_APPROACH_STEP*3)
            if grasp_retract_interpolate != False:
                rospy.sleep(0.8)
                print "###########Successfully grasped and retracted out of bin"
                state = 7 # grasped
            else:
                g_left_gripper.open()
                print "######### Could not retract"
                state = 8 # robot fail to move the object up
        else:
            g_left_gripper.open()
            print "######### Could not raise"
            state = 8 # robot fail to move the object up
    else:
        print "######### Could not grasp"
        state = 8 # robot fail to get close to object
    
    header = std_msgs.msg.Header()
    g_motion_planner_state_publisher.publish(header, state)
    
    return state

        
def motion_planner():
    global g_decision_making_state
    global g_decision_making_state_available
    global g_motion_planner_state_publisher
    global g_limb
    global g_left_gripper
    global g_origin_robot_position
    global g_bin_robot_position
    global g_map_robot_position_1
    global g_map_robot_position_2
    global g_away_from_bin
    global g_to_order_bin_robot_position1
    global g_to_order_bin_robot_position2
    global g_endpoint_state
    global g_endpoint_state_available
    global g_object_pose
 
    if g_decision_making_state_available == True:
        state = 0 # none
        current_motion_planning_mode = g_decision_making_state.motion_planning_mode
        header = std_msgs.msg.Header()

        if current_motion_planning_mode == 6: # mp_to_O -> move to origin
            g_limb.move_to_joint_positions(g_origin_robot_position);
            g_left_gripper.close()
            state = 1 # robot is at the origin
            g_motion_planner_state_publisher.publish(header, state)

        if current_motion_planning_mode == 7: # mp_to_B -> move to Bin
            g_limb.move_to_joint_positions(g_bin_robot_position);
            state = 2 # robot is at the bin
            g_motion_planner_state_publisher.publish(header, state)

        if current_motion_planning_mode == 8: # mp_to_M -> move to map
            g_limb.move_to_joint_positions(g_map_robot_position_2);
            g_limb.move_to_joint_positions(g_map_robot_position_1);
            rospy.sleep(6.0)
            state = 3 # bin mapped
            g_motion_planner_state_publisher.publish(header, state)

        if current_motion_planning_mode == 9: # mp_to_Ob_ -> move closer to object
            state = move_closer_to_object()

        if current_motion_planning_mode == 12: # grasp -> grasp move
            state = grasp()
    
        if current_motion_planning_mode == 10: # mp_to_AB_ -> move away from bin
            g_limb.move_to_joint_positions(g_away_from_bin);
            state = 5 # robot is away from object
            g_motion_planner_state_publisher.publish(header, state)

        if current_motion_planning_mode == 11: # mp_to_OB -> move to order bin
            g_limb.move_to_joint_positions(g_to_order_bin_robot_position1);
            g_limb.move_to_joint_positions(g_to_order_bin_robot_position2);
            g_left_gripper.open()
            state = 6 # robot is at the order bin
            g_motion_planner_state_publisher.publish(header, state)
             
        print "motion planner new state = ", state, "decision making state = ", g_decision_making_state.state, "current motion planning mode = ", current_motion_planning_mode
        rospy.sleep(0.5)
        g_decision_making_state_available = False

    return


def decision_making_state_handler(data):
    global g_decision_making_state
    global g_decision_making_state_available

    g_decision_making_state = data
    g_decision_making_state_available = True
    return

    
def endpoint_state_state_handler(data):
    global g_endpoint_state
    global g_endpoint_state_available

    g_endpoint_state = data
    g_endpoint_state_available = True
    return
    
    
def motion_planner_int():
    global g_origin_robot_position
    global g_bin_robot_position
    global g_map_robot_position_1
    global g_map_robot_position_2
    global g_away_from_bin
    global g_to_order_bin_robot_position1
    global g_to_order_bin_robot_position2

    g_origin_robot_position = {'left_w0': -2.3285828333496097, 'left_w1': 1.0131943092407227, 'left_w2': 1.523242920629883, 'left_e0': -0.9506845922058106, 'left_e1': 2.2495828228637698, 'left_s0': 0.6201117327941895, 'left_s1': 0.5553010445800781}
    g_bin_robot_position = {'left_w0': -2.4275245940551757, 'left_w1': 0.013038836682128907, 'left_w2': 1.515956511895752, 'left_e0': -1.1462671424377442, 'left_e1': 2.1241798935974123, 'left_s0': 1.4116458184387208, 'left_s1': 0.49585928911743166}
    g_map_robot_position_1 = {'left_w0': -2.475461493621826, 'left_w1': -0.002684466375732422, 'left_w2': 1.515956511895752, 'left_e0': -1.2317865712646485, 'left_e1': 2.1506410621582033, 'left_s0': 1.4020584385253907, 'left_s1': 0.505830164227295}
    g_map_robot_position_2 = {'left_w0': -2.4708595512634277, 'left_w1': -0.004218447161865235, 'left_w2': 1.498699228051758, 'left_e0': -1.1455001520446777, 'left_e1': 2.0704905660827637, 'left_s0': 1.3832671738952638, 'left_s1': 0.49355831793823246}
    g_away_from_bin = {'left_w0': -2.8271265888427735, 'left_w1': 0.24735440176391604, 'left_w2': 1.4354225206237794, 'left_e0': -1.517873987878418, 'left_e1': 1.84614587611084, 'left_s0': 0.747432138043213, 'left_s1': 0.19098060787353516}
    g_to_order_bin_robot_position1 = {'left_w0': -2.8271265888427735, 'left_w1': 0.24735440176391604, 'left_w2': 1.4354225206237794, 'left_e0': -1.517873987878418, 'left_e1': 1.84614587611084, 'left_s0': 0.747432138043213, 'left_s1': 0.19098060787353516} 
    g_to_order_bin_robot_position2 = {'left_w0': -1.191136080432129, 'left_w1': -1.4415584437683107, 'left_w2': 0.5204029816955567, 'left_e0': -1.7924565485961916, 'left_e1': 0.8877913799743653, 'left_s0': 0.6975777624938966, 'left_s1': 0.34476218168334966} 

#     g_origin_robot_position = {'left_w0': -2.3285828333496097, 'left_w1': 1.0131943092407227, 'left_w2': 1.523242920629883, 'left_e0': -0.9506845922058106, 'left_e1': 2.2495828228637698, 'left_s0': 0.6201117327941895, 'left_s1': 0.5553010445800781}
#     g_bin_robot_position = {'left_w0': -2.5260828595642093, 'left_w1': 0.1449611842895508, 'left_w2': 1.5589079739074707, 'left_e0': -0.985582655090332, 'left_e1': 2.478145959997559, 'left_s0': 1.4032089241149903, 'left_s1': 0.2688301327697754}
#     g_map_robot_position_1 = {'left_w0': -2.5260828595642093, 'left_w1': 0.1449611842895508, 'left_w2': 1.5589079739074707, 'left_e0': -0.985582655090332, 'left_e1': 2.478145959997559, 'left_s0': 1.4032089241149903, 'left_s1': 0.2688301327697754}
#     g_map_robot_position_2 = {'left_w0': -2.5260828595642093, 'left_w1': 0.1449611842895508, 'left_w2': 1.5589079739074707, 'left_e0': -0.985582655090332, 'left_e1': 2.478145959997559, 'left_s0': 1.4032089241149903, 'left_s1': 0.2688301327697754}
#     g_away_from_bin = {'left_w0': -2.9061265993286134, 'left_w1': 0.9660244000671387, 'left_w2': 1.6156652629943848, 'left_e0': -1.3771312507507325, 'left_e1': 2.0647381381347656, 'left_s0': 0.29797576770629886, 'left_s1': 0.22587867075805665}
#     g_to_order_bin_robot_position1 = {'left_w0': -2.8271265888427735, 'left_w1': 0.24735440176391604, 'left_w2': 1.4354225206237794, 'left_e0': -1.517873987878418, 'left_e1': 1.84614587611084, 'left_s0': 0.747432138043213, 'left_s1': 0.19098060787353516} 
#     g_to_order_bin_robot_position2 = {'left_w0': -1.191136080432129, 'left_w1': -1.4415584437683107, 'left_w2': 0.5204029816955567, 'left_e0': -1.7924565485961916, 'left_e1': 0.8877913799743653, 'left_s0': 0.6975777624938966, 'left_s1': 0.34476218168334966} 


def motion_planner_main():
    global g_motion_planner_state_publisher
    global g_limb
    global g_left_gripper
    global g_tf_listener
  
    rospy.init_node('motion_planner', anonymous=True)

    # Subscribers
    rospy.Subscriber("/decision_making_state", DecisionMakingStateMessage, decision_making_state_handler)
    rospy.Subscriber("/robot/limb/left/endpoint_state", EndpointState, endpoint_state_state_handler)
    
    # Tf Listener
    g_tf_listener = tf.TransformListener()
    
    # Publishers
    g_motion_planner_state_publisher = rospy.Publisher('/motion_planner_state', MotionPlanningStateMessage, queue_size=1)

    # Initializations
    motion_planner_int()
    
    # Enable robot
    rs = baxter_interface.RobotEnable(CHECK_VERSION)
    rs.enable()
    
    # Set current limb
    g_limb = baxter_interface.Limb('left')
    
    # Set and calibrate gripper
    g_left_gripper = baxter_interface.Gripper('left')
    if g_left_gripper.error():
        g_left_gripper.reset()
    if (not g_left_gripper.calibrated() and g_left_gripper.type() != 'custom'):
        g_left_gripper.calibrate()
    
    # Main loop
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        motion_planner()
        rate.sleep()

    return


if __name__ == '__main__':
    motion_planner_main()
