#!/usr/bin/env python

import sys 
import tf
import numpy
import math


import std_msgs.msg
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)


# rel_path = os.path.dirname(__file__)
# abs_path = os.path.abspath(rel_path)
# root_path_rev = os.path.relpath('/' + abs_path[::-1], '/' + rel_path[::-1])
# root_path = root_path_rev[::-1]
# print abs_path
# print rel_path
# print root_path
# filename = os.path.join(dir, '/relative/path/to/file/you/want')

def grasp_main():
  global d_to_r

  d_to_r = math.pi / 180.0 # degree to radian
  object_name = 'expo_dry_erase_board_eraser'
  # print object_name
  grasp = {}
  index = 0
  # grasp = [[0 for x in range(5)] for x in range(5)] 
  # print grasp

  # if object_name == 'oreo_mega_stuf':
  grasp[object_name] = {}
  # pose = Pose()
  # pose.position.x = 0
  # pose.position.y = 0
  # pose.position.z = 0
  # pose.orientation.x = 0#temp_pose[0]
  # pose.orientation.y = 0#temp_pose[1]
  # pose.orientation.z = 0.17#temp_pose[2]
  # pose.orientation.w = 0.9962 #temp_pose[3]
  # grasp[object_name][index] = pose

  angle_resolution = 5 #degree
    

  alpha_range = 90
  beta_range = 0
  gamma_range = 0
  origin, xaxis, yaxis, zaxis = [0, 0, 0], [1, 0, 0], [0, 1, 0], [0, 0, 1]
  o_pose = Pose()
  o_pose.position.x = 0
  o_pose.position.y = 0
  o_pose.position.z = 0
  o_pose.orientation.x = 0
  o_pose.orientation.y = 0
  o_pose.orientation.z = 0
  o_pose.orientation.w = 1
  print_angles(o_pose)

  for i in range(1, beta_range/angle_resolution + 1):
    # print 'beta'
    pose = Pose()
    pose.position.x = 0
    pose.position.y = 0
    pose.position.z = 0
    beta = d_to_r * (- beta_range/2 + i * angle_resolution)
    temp_pose = tf.transformations.quaternion_about_axis( beta, yaxis)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose
    print_angles(pose)
    print_rpy(pose)


    o_pose.orientation = rotate_orientation(o_pose.orientation, pose.orientation)

    print_angles(o_pose)
    print_rpy(o_pose)

    index += 1


  for j in range(1, alpha_range/angle_resolution + 1):
    # print 'alpha'
    pose = Pose()
    alpha = d_to_r * (- alpha_range/2 + j * angle_resolution)
    # print 'alpha = ', alpha
    temp_pose = tf.transformations.quaternion_about_axis(alpha, xaxis)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose
    print_angles(pose)
    print_rpy(pose)
    o_pose.orientation = rotate_orientation(o_pose.orientation, pose.orientation)

    print_angles(o_pose)
    print_rpy(o_pose)
    index += 1


  for k in range(1, gamma_range/angle_resolution + 1):
    # print 'gamma'
    pose = Pose()
    gamma = d_to_r * (- gamma_range/2 + k * angle_resolution) 
    temp_pose = tf.transformations.quaternion_about_axis(gamma, zaxis)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose

    angles = tf.transformations.euler_from_quaternion(quaternion_from_orientation(pose.orientation))
    print [x/d_to_r for x in angles]
    print_angles(pose)
    print_rpy(pose)
    o_pose.orientation = rotate_orientation(o_pose.orientation, pose.orientation)

    print_angles(o_pose)
    print_rpy(o_pose)
    index += 1
        # print index
        # print grasp

    # print grasp

#   save_path = './data/' + object_name + '.json'
#   with open(save_path, 'w') as f:
#     json.dump(grasp, f)

# # elsewhere...

#   with open(save_path) as f:
#     loaded_grasp = json.load(f)

  print index
  save_path = './data/' + object_name
  # print save_path
  numpy.savez(save_path, grasp = [grasp])
  # grasp_publisher = rospy.Publisher('/grasp', , queue_size =10)
  # data_path = root_path + '/data/' + object_name + '.npy'
  # print data_path
  loaded_file = numpy.load(save_path + '.npz' )
  # print index
  # print len(loaded_file[object_name])

  loaded_grasp =  loaded_file['grasp'][0]
  num_of_grasp = len(loaded_grasp[object_name])
  # print loaded_grasp
  # for i in range(0,num_of_grasp):
  #   print i
  #   print loaded_grasp[object_name][i]
  #   print_angles(loaded_grasp[object_name][i])

  # Main loop
  # rate = rospy.Rate(5) # hz
  # while not rospy.is_shutdown():
  #   grasp_publisher.publish(grasp)
  #   rate.sleep()

  # return
def quaternion_from_orientation(orientation):
  return [orientation.x, orientation.y, orientation.z, orientation.w]

def print_rpy(pose):
  Rq = tf.transformations.quaternion_matrix(quaternion_from_orientation(pose.orientation))
  angles, direc, Point = tf.transformations.rotation_from_matrix(Rq)
  print angles/d_to_r, direc
  # print angles[0] * 180.0 / math.pi, ", ", angles[1] * 180.0 / math.pi, ", ", angles[2] * 180.0 / math.pi
    
  return

def print_angles(pose):
  angles = tf.transformations.euler_from_quaternion(quaternion_from_orientation(pose.orientation))
  print angles[0] * 180.0 / math.pi, ", ", angles[1] * 180.0 / math.pi, ", ", angles[2] * 180.0 / math.pi
  
  return

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

  new_orientation = tf.transformations.quaternion_multiply(_orientation, _rotation)

  orientation_rotated = Quaternion()
  orientation_rotated.x = new_orientation[0]
  orientation_rotated.y = new_orientation[1]
  orientation_rotated.z = new_orientation[2]
  orientation_rotated.w = new_orientation[3]

  return orientation_rotated


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  grasp_main()

