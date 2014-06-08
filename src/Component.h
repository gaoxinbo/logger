// File: Component.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-28
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

#include <pthread.h>
#include <sys/time.h>
#include <sstream>
#include <string>
#include "LogEvent.h"
#include "Level.h"

namespace logger {

class Component {
  public:
    Component();
    virtual ~Component() = 0;

    virtual void append(const LogEvent & le, std::ostringstream &oss) = 0;
    std::string getName() {
      return name_;
    }

  private:
    Component(const Component&);
    void operator=(const Component&);

  protected:
    std::string name_;
};


/**
 * output the user`s msg
 */
class MsgComponent : public Component {
  public:
    MsgComponent() : Component() {
      name_ = "MsgComponent";
    }
    virtual ~MsgComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss << " ";
      oss << le.msg_;
    }
};

/**
 * output the file name and the line number 
 */
class FileComponent : public Component {
  public:
    FileComponent() : Component() {
      name_ = "FileComponent";
    }
    virtual ~FileComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(le.file_ == NULL)
        return;
      if(oss.str().length()>0)
        oss << " ";
      oss << le.file_ << ":" << le.line_;
    }
};

/**
 * output the level information
 */
class LevelComponent : public Component {
  public:
    LevelComponent() : Component() {
      name_ = "LevelComponent";
    }
    virtual ~LevelComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss<<" ";
      oss<<LevelMsg[le.level_];
    }

};


/**
 * output the current time. for now we can`t specify the format
 */
class TimeComponent : public Component {
  public:
    TimeComponent() : Component() {
      name_ = "TimeComponent";
    }
    virtual ~TimeComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss<<" ";

      char buf[30]; 
      time_t now = time(NULL);
      tm  t;
      localtime_r(&now,&t);
      int n = strftime(buf,30,"%Y-%m-%d %H:%M:%S",&t);
      oss<<buf;
    }

};

class LogNameComponent : public Component {
  public:
    LogNameComponent() : Component() {
      name_ = "LogNameComponent";
    }
    virtual ~LogNameComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss<<" ";
      oss<<le.logName_;
    }
    
};

class PidComponent : public Component {
  public:
    PidComponent() : Component() {
      name_ = "PidComponent";
    }
    virtual ~PidComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss<<" ";
      oss<<pthread_self();
    }
    
};

class TidComponent : public Component {
  public:
    TidComponent() : Component() {
      name_ = "TidComponent";
    }
    virtual ~TidComponent() {}

    virtual void append(const LogEvent & le, std::ostringstream &oss) {
      if(oss.str().length()>0)
        oss<<" ";
      oss<<pthread_self();
    }
    
};

}  // namespace logger
#endif  // _COMPONENT_H_

