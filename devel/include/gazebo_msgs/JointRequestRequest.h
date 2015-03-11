/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /Users/Shaojun/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv
 *
 */


#ifndef GAZEBO_MSGS_MESSAGE_JOINTREQUESTREQUEST_H
#define GAZEBO_MSGS_MESSAGE_JOINTREQUESTREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gazebo_msgs
{
template <class ContainerAllocator>
struct JointRequestRequest_
{
  typedef JointRequestRequest_<ContainerAllocator> Type;

  JointRequestRequest_()
    : joint_name()  {
    }
  JointRequestRequest_(const ContainerAllocator& _alloc)
    : joint_name(_alloc)  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _joint_name_type;
  _joint_name_type joint_name;




  typedef boost::shared_ptr< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct JointRequestRequest_

typedef ::gazebo_msgs::JointRequestRequest_<std::allocator<void> > JointRequestRequest;

typedef boost::shared_ptr< ::gazebo_msgs::JointRequestRequest > JointRequestRequestPtr;
typedef boost::shared_ptr< ::gazebo_msgs::JointRequestRequest const> JointRequestRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/Users/Shaojun/ros_catkin_ws/install_isolated/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/Users/Shaojun/ros_catkin_ws/install_isolated/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/Users/Shaojun/ros_catkin_ws/install_isolated/share/trajectory_msgs/cmake/../msg'], 'gazebo_msgs': ['/Users/Shaojun/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg'], 'geometry_msgs': ['/Users/Shaojun/ros_catkin_ws/install_isolated/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0be1351618e1dc030eb7959d9a4902de";
  }

  static const char* value(const ::gazebo_msgs::JointRequestRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0be1351618e1dc03ULL;
  static const uint64_t static_value2 = 0x0eb7959d9a4902deULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/JointRequestRequest";
  }

  static const char* value(const ::gazebo_msgs::JointRequestRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string joint_name\n\
";
  }

  static const char* value(const ::gazebo_msgs::JointRequestRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.joint_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct JointRequestRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::JointRequestRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_msgs::JointRequestRequest_<ContainerAllocator>& v)
  {
    s << indent << "joint_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.joint_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_JOINTREQUESTREQUEST_H
