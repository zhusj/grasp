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
 * Auto-generated by gensrv_cpp from file /home/pracsys/catkin_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv
 *
 */


#ifndef GAZEBO_MSGS_MESSAGE_DELETEMODEL_H
#define GAZEBO_MSGS_MESSAGE_DELETEMODEL_H

#include <ros/service_traits.h>


#include <gazebo_msgs/DeleteModelRequest.h>
#include <gazebo_msgs/DeleteModelResponse.h>


namespace gazebo_msgs
{

struct DeleteModel
{

typedef DeleteModelRequest Request;
typedef DeleteModelResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct DeleteModel
} // namespace gazebo_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::gazebo_msgs::DeleteModel > {
  static const char* value()
  {
    return "9ce56b4e9e54616de25d796dc972a262";
  }

  static const char* value(const ::gazebo_msgs::DeleteModel&) { return value(); }
};

template<>
struct DataType< ::gazebo_msgs::DeleteModel > {
  static const char* value()
  {
    return "gazebo_msgs/DeleteModel";
  }

  static const char* value(const ::gazebo_msgs::DeleteModel&) { return value(); }
};


// service_traits::MD5Sum< ::gazebo_msgs::DeleteModelRequest> should match 
// service_traits::MD5Sum< ::gazebo_msgs::DeleteModel > 
template<>
struct MD5Sum< ::gazebo_msgs::DeleteModelRequest>
{
  static const char* value()
  {
    return MD5Sum< ::gazebo_msgs::DeleteModel >::value();
  }
  static const char* value(const ::gazebo_msgs::DeleteModelRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::gazebo_msgs::DeleteModelRequest> should match 
// service_traits::DataType< ::gazebo_msgs::DeleteModel > 
template<>
struct DataType< ::gazebo_msgs::DeleteModelRequest>
{
  static const char* value()
  {
    return DataType< ::gazebo_msgs::DeleteModel >::value();
  }
  static const char* value(const ::gazebo_msgs::DeleteModelRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::gazebo_msgs::DeleteModelResponse> should match 
// service_traits::MD5Sum< ::gazebo_msgs::DeleteModel > 
template<>
struct MD5Sum< ::gazebo_msgs::DeleteModelResponse>
{
  static const char* value()
  {
    return MD5Sum< ::gazebo_msgs::DeleteModel >::value();
  }
  static const char* value(const ::gazebo_msgs::DeleteModelResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::gazebo_msgs::DeleteModelResponse> should match 
// service_traits::DataType< ::gazebo_msgs::DeleteModel > 
template<>
struct DataType< ::gazebo_msgs::DeleteModelResponse>
{
  static const char* value()
  {
    return DataType< ::gazebo_msgs::DeleteModel >::value();
  }
  static const char* value(const ::gazebo_msgs::DeleteModelResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // GAZEBO_MSGS_MESSAGE_DELETEMODEL_H
