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




def rank_grasp_main():

  rospy.Subscriber("/grasp", , grasp)
  ranked_grasp = grasp;
  ranked_grasp_publisher = rospy.Publisher('/grasp', , queue_size =10)

  # Main loop
  rate = rospy.Rate(5) # hz
  while not rospy.is_shutdown():
    grasp_publisher.publish(ranked_grasp)
    rate.sleep()

  return


# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  rank_grasp_main()

