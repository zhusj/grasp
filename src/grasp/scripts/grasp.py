#!/usr/bin/env python

import sys 
import rospy
import tf

import std_msgs.msg
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)




def grasp_main():

  object_name = 'expo_dry_erase_board_eraser'
  print object_name
  grasp = {}
  index = 0
  # grasp = [[0 for x in range(5)] for x in range(5)] 
  # print grasp

  # if object_name == 'oreo_mega_stuf':
  grasp[object_name] = {}
  angle_resolution = 5 #degree
  for i in range(1, 180/angle_resolution):
    grasp[object_name] = {}
    pose = Pose()
    pose.position.x = 0
    pose.position.y = 0
    pose.position.z = 0
    beta = - 90 + i * angle_resolution
    for j in range(1, 30/angle_resolution):
      alpha = - 15 + j * angle_resolution
      for k in range(1, 30/angle_resolution):
        gamma = - 15 + k * angle_resolution 
        temp_pose = tf.transformations.quaternion_from_euler(alpha, beta, gamma)

        pose.orientation.x = temp_pose[0]
        pose.orientation.y = temp_pose[1]
        pose.orientation.z = temp_pose[2]
        pose.orientation.w = temp_pose[3]
        grasp[object_name][index] = pose
        index += 1
    print grasp

  print index

  grasp_publisher = rospy.Publisher('/grasp', , queue_size =10)

  # Main loop
  rate = rospy.Rate(5) # hz
  while not rospy.is_shutdown():
    grasp_publisher.publish(grasp)
    rate.sleep()

  return


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  grasp_main()

