//#line 2 "/opt/ros/hydro/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
// 
// File autogenerated for the prx_motion_planning3 package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __prx_motion_planning3__PRX_MOTION_PLANNING3CONFIG_H__
#define __prx_motion_planning3__PRX_MOTION_PLANNING3CONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace prx_motion_planning3
{
  class prx_motion_planning3ConfigStatics;
  
  class prx_motion_planning3Config
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(prx_motion_planning3Config &config, const prx_motion_planning3Config &max, const prx_motion_planning3Config &min) const = 0;
      virtual void calcLevel(uint32_t &level, const prx_motion_planning3Config &config1, const prx_motion_planning3Config &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, prx_motion_planning3Config &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const prx_motion_planning3Config &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, prx_motion_planning3Config &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const prx_motion_planning3Config &config) const = 0;
      virtual void getValue(const prx_motion_planning3Config &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T prx_motion_planning3Config::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (prx_motion_planning3Config::* field);

      virtual void clamp(prx_motion_planning3Config &config, const prx_motion_planning3Config &max, const prx_motion_planning3Config &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const prx_motion_planning3Config &config1, const prx_motion_planning3Config &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, prx_motion_planning3Config &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const prx_motion_planning3Config &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, prx_motion_planning3Config &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const prx_motion_planning3Config &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const prx_motion_planning3Config &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, prx_motion_planning3Config &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    template<class T, class PT>
    class GroupDescription : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string name, std::string type, int parent, int id, bool s, T PT::* f) : AbstractGroupDescription(name, type, parent, id, s), field(f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, prx_motion_planning3Config &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<prx_motion_planning3Config::AbstractGroupDescriptionConstPtr> groups;
    };
    
class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(prx_motion_planning3Config &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("first_rotating_axis"==(*_i)->name){first_rotating_axis = boost::any_cast<int>(val);}
        if("first_rotating_axis_signal"==(*_i)->name){first_rotating_axis_signal = boost::any_cast<double>(val);}
        if("second_rotating_axis"==(*_i)->name){second_rotating_axis = boost::any_cast<int>(val);}
        if("second_rotating_axis_signal"==(*_i)->name){second_rotating_axis_signal = boost::any_cast<double>(val);}
      }
    }

    int first_rotating_axis;
double first_rotating_axis_signal;
int second_rotating_axis;
double second_rotating_axis_signal;

    bool state;
    std::string name;

    
}groups;



//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int first_rotating_axis;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double first_rotating_axis_signal;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int second_rotating_axis;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double second_rotating_axis_signal;
//#line 255 "/opt/ros/hydro/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("prx_motion_planning3Config::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const prx_motion_planning3Config &__max__ = __getMax__();
      const prx_motion_planning3Config &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const prx_motion_planning3Config &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const prx_motion_planning3Config &__getDefault__();
    static const prx_motion_planning3Config &__getMax__();
    static const prx_motion_planning3Config &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();
    
  private:
    static const prx_motion_planning3ConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void prx_motion_planning3Config::ParamDescription<std::string>::clamp(prx_motion_planning3Config &config, const prx_motion_planning3Config &max, const prx_motion_planning3Config &min) const
  {
    return;
  }

  class prx_motion_planning3ConfigStatics
  {
    friend class prx_motion_planning3Config;
    
    prx_motion_planning3ConfigStatics()
    {
prx_motion_planning3Config::GroupDescription<prx_motion_planning3Config::DEFAULT, prx_motion_planning3Config> Default("Default", "", 0, 0, true, &prx_motion_planning3Config::groups);
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.first_rotating_axis = 0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.first_rotating_axis = 3;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.first_rotating_axis = 2;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<int>("first_rotating_axis", "int", 2, "First rotating axis (0 = none, 1 = x, 2 = y, 3 = z)", "", &prx_motion_planning3Config::first_rotating_axis)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<int>("first_rotating_axis", "int", 2, "First rotating axis (0 = none, 1 = x, 2 = y, 3 = z)", "", &prx_motion_planning3Config::first_rotating_axis)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.first_rotating_axis_signal = -1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.first_rotating_axis_signal = 1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.first_rotating_axis_signal = 1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<double>("first_rotating_axis_signal", "double", 1.0, "First rotating axis signal", "", &prx_motion_planning3Config::first_rotating_axis_signal)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<double>("first_rotating_axis_signal", "double", 1.0, "First rotating axis signal", "", &prx_motion_planning3Config::first_rotating_axis_signal)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.second_rotating_axis = 0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.second_rotating_axis = 3;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.second_rotating_axis = 2;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<int>("second_rotating_axis", "int", 2, "Second rotating axis (0 = none, 1 = x, 2 = y, 3 = z)", "", &prx_motion_planning3Config::second_rotating_axis)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<int>("second_rotating_axis", "int", 2, "Second rotating axis (0 = none, 1 = x, 2 = y, 3 = z)", "", &prx_motion_planning3Config::second_rotating_axis)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.second_rotating_axis_signal = -1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.second_rotating_axis_signal = 1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.second_rotating_axis_signal = 1.0;
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<double>("second_rotating_axis_signal", "double", 1.0, "Second rotating axis signal", "", &prx_motion_planning3Config::second_rotating_axis_signal)));
//#line 262 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(prx_motion_planning3Config::AbstractParamDescriptionConstPtr(new prx_motion_planning3Config::ParamDescription<double>("second_rotating_axis_signal", "double", 1.0, "Second rotating axis signal", "", &prx_motion_planning3Config::second_rotating_axis_signal)));
//#line 233 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 233 "/opt/ros/hydro/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(prx_motion_planning3Config::AbstractGroupDescriptionConstPtr(new prx_motion_planning3Config::GroupDescription<prx_motion_planning3Config::DEFAULT, prx_motion_planning3Config>(Default)));
//#line 390 "/opt/ros/hydro/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<prx_motion_planning3Config::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__); 
    }
    std::vector<prx_motion_planning3Config::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<prx_motion_planning3Config::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    prx_motion_planning3Config __max__;
    prx_motion_planning3Config __min__;
    prx_motion_planning3Config __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const prx_motion_planning3ConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static prx_motion_planning3ConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &prx_motion_planning3Config::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const prx_motion_planning3Config &prx_motion_planning3Config::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const prx_motion_planning3Config &prx_motion_planning3Config::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const prx_motion_planning3Config &prx_motion_planning3Config::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<prx_motion_planning3Config::AbstractParamDescriptionConstPtr> &prx_motion_planning3Config::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<prx_motion_planning3Config::AbstractGroupDescriptionConstPtr> &prx_motion_planning3Config::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const prx_motion_planning3ConfigStatics *prx_motion_planning3Config::__get_statics__()
  {
    const static prx_motion_planning3ConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = prx_motion_planning3ConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __PRX_MOTION_PLANNING3RECONFIGURATOR_H__
