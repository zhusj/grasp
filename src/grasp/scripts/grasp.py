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

  angle_resolution = 10 #degree
  k = math.pi / 180.0 # degree to radian
  for i in range(0, 20/angle_resolution + 1):
    pose = Pose()
    pose.position.x = 0
    pose.position.y = 0
    pose.position.z = 0
    beta = k * (- 10 + i * angle_resolution)
    temp_pose = tf.transformations.quaternion_from_euler(0, beta, 0)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose
    index += 1


  for j in range(0, 20/angle_resolution + 1):
    alpha = k * (- 10 + j * angle_resolution)
    temp_pose = tf.transformations.quaternion_from_euler(alpha, 0, 0)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose
    index += 1




  for k in range(0, 20/angle_resolution + 1):
    gamma = k * (- 10 + k * angle_resolution) 
    temp_pose = tf.transformations.quaternion_from_euler(0, 0, gamma)

    pose.orientation.x = temp_pose[0]
    pose.orientation.y = temp_pose[1]
    pose.orientation.z = temp_pose[2]
    pose.orientation.w = temp_pose[3]
    grasp[object_name][index] = pose
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
  print loaded_grasp[object_name][0]
  print_angles(loaded_grasp[object_name][0])

  # Main loop
  # rate = rospy.Rate(5) # hz
  # while not rospy.is_shutdown():
  #   grasp_publisher.publish(grasp)
  #   rate.sleep()

  # return
def quaternion_from_orientation(orientation):
  return [orientation.x, orientation.y, orientation.z, orientation.w]

def print_angles(pose):
  angles = tf.transformations.euler_from_quaternion(quaternion_from_orientation(pose.orientation))
  print angles[0] * 180.0 / math.pi, ", ", angles[1] * 180.0 / math.pi, ", ", angles[2] * 180.0 / math.pi
    
  return


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  grasp_main()

