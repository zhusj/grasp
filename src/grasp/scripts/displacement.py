#!/usr/bin/env python

import sys 
import tf
import numpy
import os


import std_msgs.msg
from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)

def displacement_main():

  object_name = ['champion_copper_plus_spark_plug', 'crayola_64_ct', 'highland_6539_self_stick_notes']
  
  displacement = {}
  for i in range(0, len(object_name)):
    # print i
    displacement[object_name[i]] = 1

  save_path = './data/displacement'
  numpy.save(save_path, displacement)

  loaded_displacement = numpy.load(save_path + '.npy' )
  print loaded_displacement

if __name__ == '__main__':
  displacement_main()

