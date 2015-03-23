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
 * Auto-generated by genmsg_cpp from file /home/pracsys/catkin_ws/src/baxter_common/baxter_core_msgs/msg/ITBState.msg
 *
 */


#ifndef BAXTER_CORE_MSGS_MESSAGE_ITBSTATE_H
#define BAXTER_CORE_MSGS_MESSAGE_ITBSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace baxter_core_msgs
{
template <class ContainerAllocator>
struct ITBState_
{
  typedef ITBState_<ContainerAllocator> Type;

  ITBState_()
    : buttons()
    , up(false)
    , down(false)
    , left(false)
    , right(false)
    , wheel(0)
    , innerLight(false)
    , outerLight(false)  {
      buttons.assign(false);
  }
  ITBState_(const ContainerAllocator& _alloc)
    : buttons()
    , up(false)
    , down(false)
    , left(false)
    , right(false)
    , wheel(0)
    , innerLight(false)
    , outerLight(false)  {
      buttons.assign(false);
  }



   typedef boost::array<uint8_t, 4>  _buttons_type;
  _buttons_type buttons;

   typedef uint8_t _up_type;
  _up_type up;

   typedef uint8_t _down_type;
  _down_type down;

   typedef uint8_t _left_type;
  _left_type left;

   typedef uint8_t _right_type;
  _right_type right;

   typedef uint8_t _wheel_type;
  _wheel_type wheel;

   typedef uint8_t _innerLight_type;
  _innerLight_type innerLight;

   typedef uint8_t _outerLight_type;
  _outerLight_type outerLight;




  typedef boost::shared_ptr< ::baxter_core_msgs::ITBState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::baxter_core_msgs::ITBState_<ContainerAllocator> const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;

}; // struct ITBState_

typedef ::baxter_core_msgs::ITBState_<std::allocator<void> > ITBState;

typedef boost::shared_ptr< ::baxter_core_msgs::ITBState > ITBStatePtr;
typedef boost::shared_ptr< ::baxter_core_msgs::ITBState const> ITBStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::baxter_core_msgs::ITBState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::baxter_core_msgs::ITBState_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace baxter_core_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/hydro/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/hydro/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/hydro/share/geometry_msgs/cmake/../msg'], 'baxter_core_msgs': ['/home/pracsys/catkin_ws/src/baxter_common/baxter_core_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::baxter_core_msgs::ITBState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::baxter_core_msgs::ITBState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::baxter_core_msgs::ITBState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fd86ad89da05230247c94b4d8e7ed306";
  }

  static const char* value(const ::baxter_core_msgs::ITBState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xfd86ad89da052302ULL;
  static const uint64_t static_value2 = 0x47c94b4d8e7ed306ULL;
};

template<class ContainerAllocator>
struct DataType< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "baxter_core_msgs/ITBState";
  }

  static const char* value(const ::baxter_core_msgs::ITBState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool[4] buttons\n\
bool    up\n\
bool    down\n\
bool    left\n\
bool    right\n\
uint8   wheel\n\
\n\
# true if the inner light is on, false if not\n\
bool innerLight\n\
\n\
# true if the outer light is on, false if not\n\
bool outerLight\n\
";
  }

  static const char* value(const ::baxter_core_msgs::ITBState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.buttons);
      stream.next(m.up);
      stream.next(m.down);
      stream.next(m.left);
      stream.next(m.right);
      stream.next(m.wheel);
      stream.next(m.innerLight);
      stream.next(m.outerLight);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct ITBState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::baxter_core_msgs::ITBState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::baxter_core_msgs::ITBState_<ContainerAllocator>& v)
  {
    s << indent << "buttons[]" << std::endl;
    for (size_t i = 0; i < v.buttons.size(); ++i)
    {
      s << indent << "  buttons[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.buttons[i]);
    }
    s << indent << "up: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.up);
    s << indent << "down: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.down);
    s << indent << "left: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.left);
    s << indent << "right: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.right);
    s << indent << "wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wheel);
    s << indent << "innerLight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.innerLight);
    s << indent << "outerLight: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.outerLight);
  }
};

} // namespace message_operations
} // namespace ros

#endif // BAXTER_CORE_MSGS_MESSAGE_ITBSTATE_H
