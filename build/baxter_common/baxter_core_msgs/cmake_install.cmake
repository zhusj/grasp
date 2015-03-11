# Install script for directory: /Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/Shaojun/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs/msg" TYPE FILE FILES
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/AnalogIOState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/AnalogIOStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/AnalogOutputCommand.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/AssemblyState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/AssemblyStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/CameraControl.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/CameraSettings.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/CollisionAvoidanceState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/CollisionDetectionState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/DigitalIOState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/DigitalIOStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/DigitalOutputCommand.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/EndEffectorCommand.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/EndEffectorProperties.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/EndEffectorState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/EndpointState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/EndpointStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/HeadPanCommand.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/HeadState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/ITBState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/ITBStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/JointCommand.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/NavigatorState.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/NavigatorStates.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/RobustControllerStatus.msg"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/msg/SEAJointState.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs/srv" TYPE FILE FILES
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/srv/CloseCamera.srv"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/srv/ListCameras.srv"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/srv/OpenCamera.srv"
    "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/srv/SolvePositionIK.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs/cmake" TYPE FILE FILES "/Users/Shaojun/catkin_ws/build/baxter_common/baxter_core_msgs/catkin_generated/installspace/baxter_core_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/Shaojun/catkin_ws/devel/include/baxter_core_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/Users/Shaojun/catkin_ws/devel/share/common-lisp/ros/baxter_core_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/Users/Shaojun/catkin_ws/devel/lib/python2.7/site-packages/baxter_core_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/site-packages" TYPE DIRECTORY FILES "/Users/Shaojun/catkin_ws/devel/lib/python2.7/site-packages/baxter_core_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/Users/Shaojun/catkin_ws/build/baxter_common/baxter_core_msgs/catkin_generated/installspace/baxter_core_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs/cmake" TYPE FILE FILES "/Users/Shaojun/catkin_ws/build/baxter_common/baxter_core_msgs/catkin_generated/installspace/baxter_core_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs/cmake" TYPE FILE FILES
    "/Users/Shaojun/catkin_ws/build/baxter_common/baxter_core_msgs/catkin_generated/installspace/baxter_core_msgsConfig.cmake"
    "/Users/Shaojun/catkin_ws/build/baxter_common/baxter_core_msgs/catkin_generated/installspace/baxter_core_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/baxter_core_msgs" TYPE FILE FILES "/Users/Shaojun/catkin_ws/src/baxter_common/baxter_core_msgs/package.xml")
endif()

