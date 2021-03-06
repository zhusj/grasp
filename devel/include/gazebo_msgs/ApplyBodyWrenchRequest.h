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
 * Auto-generated by genmsg_cpp from file /home/pracsys/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv
 *
 */


#ifndef GAZEBO_MSGS_MESSAGE_APPLYBODYWRENCHREQUEST_H
#define GAZEBO_MSGS_MESSAGE_APPLYBODYWRENCHREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>
#include <geometry_msgs/Wrench.h>

namespace gazebo_msgs
{
template <class ContainerAllocator>
struct ApplyBodyWrenchRequest_
{
  typedef ApplyBodyWrenchRequest_<ContainerAllocator> Type;

  ApplyBodyWrenchRequest_()
    : body_name()
    , reference_frame()
    , reference_point()
    , wrench()
    , start_time()
    , duration()  {
    }
  ApplyBodyWrenchRequest_(const ContainerAllocator& _alloc)
    : body_name(_alloc)
    , reference_frame(_alloc)
    , reference_point(_alloc)
    , wrench(_alloc)
    , start_time()
    , duration()  {
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _body_name_type;
  _body_name_type body_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _reference_frame_type;
  _reference_frame_type reference_frame;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _reference_point_type;
  _reference_point_type reference_point;

   typedef  ::geometry_msgs::Wrench_<ContainerAllocator>  _wrench_type;
  _wrench_type wrench;

   typedef ros::Time _start_time_type;
  _start_time_type start_time;

   typedef ros::Duration _duration_type;
  _duration_type duration;




  typedef boost::shared_ptr< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct ApplyBodyWrenchRequest_

typedef ::gazebo_msgs::ApplyBodyWrenchRequest_<std::allocator<void> > ApplyBodyWrenchRequest;

typedef boost::shared_ptr< ::gazebo_msgs::ApplyBodyWrenchRequest > ApplyBodyWrenchRequestPtr;
typedef boost::shared_ptr< ::gazebo_msgs::ApplyBodyWrenchRequest const> ApplyBodyWrenchRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gazebo_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/hydro/share/sensor_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/hydro/share/trajectory_msgs/cmake/../msg'], 'gazebo_msgs': ['/home/pracsys/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg'], 'geometry_msgs': ['/opt/ros/hydro/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e37e6adf97eba5095baa77dffb71e5bd";
  }

  static const char* value(const ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe37e6adf97eba509ULL;
  static const uint64_t static_value2 = 0x5baa77dffb71e5bdULL;
};

template<class ContainerAllocator>
struct DataType< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gazebo_msgs/ApplyBodyWrenchRequest";
  }

  static const char* value(const ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
string body_name\n\
\n\
\n\
string reference_frame\n\
\n\
\n\
geometry_msgs/Point  reference_point\n\
geometry_msgs/Wrench wrench\n\
time start_time\n\
\n\
\n\
duration duration\n\
\n\
\n\
\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Wrench\n\
# This represents force in free space, separated into\n\
# its linear and angular parts.\n\
Vector3  force\n\
Vector3  torque\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.body_name);
      stream.next(m.reference_frame);
      stream.next(m.reference_point);
      stream.next(m.wrench);
      stream.next(m.start_time);
      stream.next(m.duration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ApplyBodyWrenchRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gazebo_msgs::ApplyBodyWrenchRequest_<ContainerAllocator>& v)
  {
    s << indent << "body_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.body_name);
    s << indent << "reference_frame: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.reference_frame);
    s << indent << "reference_point: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.reference_point);
    s << indent << "wrench: ";
    s << std::endl;
    Printer< ::geometry_msgs::Wrench_<ContainerAllocator> >::stream(s, indent + "  ", v.wrench);
    s << indent << "start_time: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.start_time);
    s << indent << "duration: ";
    Printer<ros::Duration>::stream(s, indent + "  ", v.duration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_APPLYBODYWRENCHREQUEST_H
