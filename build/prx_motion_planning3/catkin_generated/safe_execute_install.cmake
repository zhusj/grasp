execute_process(COMMAND "/home/pracsys/grasp/build/prx_motion_planning3/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/pracsys/grasp/build/prx_motion_planning3/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
