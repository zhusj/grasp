# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "gazebo_msgs: 9 messages, 20 services")

set(MSG_I_FLAGS "-Igazebo_msgs:/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/hydro/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/hydro/share/sensor_msgs/cmake/../msg;-Itrajectory_msgs:/opt/ros/hydro/share/trajectory_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(gazebo_msgs_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)

### Generating Services
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetJointProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/BodyRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectory.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectoryPoint.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyJointEffort.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetWorldProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelConfiguration.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_cpp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
)

### Generating Module File
_generate_module_cpp(gazebo_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(gazebo_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(gazebo_msgs_generate_messages gazebo_msgs_generate_messages_cpp)

# target for backward compatibility
add_custom_target(gazebo_msgs_gencpp)
add_dependencies(gazebo_msgs_gencpp gazebo_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gazebo_msgs_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)

### Generating Services
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetJointProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/BodyRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectory.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectoryPoint.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyJointEffort.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetWorldProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelConfiguration.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_lisp(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
)

### Generating Module File
_generate_module_lisp(gazebo_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(gazebo_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(gazebo_msgs_generate_messages gazebo_msgs_generate_messages_lisp)

# target for backward compatibility
add_custom_target(gazebo_msgs_genlisp)
add_dependencies(gazebo_msgs_genlisp gazebo_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gazebo_msgs_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactsState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelStates.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/WorldState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_msg_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)

### Generating Services
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetJointProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/BodyRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointTrajectory.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/hydro/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectory.msg;/opt/ros/hydro/share/trajectory_msgs/cmake/../msg/JointTrajectoryPoint.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyJointEffort.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetPhysicsProperties.srv"
  "${MSG_I_FLAGS}"
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetWorldProperties.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelConfiguration.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Wrench.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)
_generate_srv_py(gazebo_msgs
  "/home/pracsys/grasp/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkProperties.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/hydro/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
)

### Generating Module File
_generate_module_py(gazebo_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(gazebo_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(gazebo_msgs_generate_messages gazebo_msgs_generate_messages_py)

# target for backward compatibility
add_custom_target(gazebo_msgs_genpy)
add_dependencies(gazebo_msgs_genpy gazebo_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gazebo_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gazebo_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(gazebo_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
add_dependencies(gazebo_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
add_dependencies(gazebo_msgs_generate_messages_cpp sensor_msgs_generate_messages_cpp)
add_dependencies(gazebo_msgs_generate_messages_cpp trajectory_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gazebo_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(gazebo_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
add_dependencies(gazebo_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
add_dependencies(gazebo_msgs_generate_messages_lisp sensor_msgs_generate_messages_lisp)
add_dependencies(gazebo_msgs_generate_messages_lisp trajectory_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gazebo_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(gazebo_msgs_generate_messages_py std_msgs_generate_messages_py)
add_dependencies(gazebo_msgs_generate_messages_py geometry_msgs_generate_messages_py)
add_dependencies(gazebo_msgs_generate_messages_py sensor_msgs_generate_messages_py)
add_dependencies(gazebo_msgs_generate_messages_py trajectory_msgs_generate_messages_py)
