#!/usr/bin/env python

import sys 
import rospy

import std_msgs.msg
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)




def grasp():

  object_name = 'expo_dry_erase_board_eraser'
  print object_name
  grasp = {}
  # grasp = [[0 for x in range(5)] for x in range(5)] 
  # print grasp

  # if object_name == 'oreo_mega_stuf':
  grasp[object_name] = {}
  for i in range(1, 10):
    grasp[object_name] = {}
    pose = Pose()
    pose.position.x = i
    pose.position.y = i
    pose.position.z = i
    pose.orientation.x = i
    pose.orientation.y = i
    pose.orientation.z = i
    pose.orientation.w = i
    grasp[object_name][i] = pose
    print grasp


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  grasp()

