// File: LogEvent.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-28
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LOGEVENT_H_
#define _LOGEVENT_H_
namespace logger {

class LogEvent {
  public:
    LogEvent();
    ~LogEvent();

    const char * msg_;
    const char * file_;
    const char * logName_;
    int level_;
    int line_;

  private:
    LogEvent(const LogEvent&);
    void operator=(const LogEvent&);
};

}  // namespace logger
#endif  // _LOGEVENT_H_

