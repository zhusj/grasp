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
 * Auto-generated by genmsg_cpp from file /Users/Shaojun/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv
 *
 */


#ifndef GAZEBO_MSGS_MESSAGE_SPAWNMODELRESPONSE_H
#define GAZEBO_MSGS_MESSAGE_SPAWNMODELRESPONSE_H


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
struct SpawnModelResponse_
{
  typedef SpawnModelResponse_<ContainerAllocator> Type;

  SpawnModelResponse_()
    : success(false)
    , status_message()  {
    }
  SpawnModelResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , status_message(_alloc)  {
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _status_message_type;
  _status_message_type status_message;




  typedef boost::shared_ptr< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct SpawnModelResponse_

typedef ::gazebo_msgs::SpawnModelResponse_<std::allocator<void> > SpawnModelResponse;

typedef boost::shared_ptr< ::gazebo_msgs::SpawnModelResponse > SpawnModelResponsePtr;
typedef boost::shared_ptr< ::gazebo_msgs::SpawnModelResponse const> SpawnModelResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ec6f3eff0161f4257b808b12bc830c2";
  }

  static const char* value(const ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ec6f3eff0161f42ULL;
  static const uint64_t static_value2 = 0x57b808b12bc830c2ULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/SpawnModelResponse";
  }

  static const char* value(const ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
string status_message\n\
\n\
";
  }

  static const char* value(const ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.status_message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct SpawnModelResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_msgs::SpawnModelResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "status_message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.status_message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_SPAWNMODELRESPONSE_H
