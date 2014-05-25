// File: appender.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _APPENDER_H_
#define _APPENDER_H_
namespace logger {

class Appender {
  public:
    Appender();
    virtual ~Appender() = 0;
    virtual void append(const char *msg) = 0 ;

  private:
    Appender(const Appender&);
    void operator=(const Appender&);
};

}  // namespace logger
#endif  // _APPENDER_H_

