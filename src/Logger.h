// File: logger.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Level.h"
#include "Appender.h"
#include "Layout.h"

namespace logger {

class Logger {
  public:
    //Logger();
    Logger(const char *name);
    ~Logger();

    void setPattern(const char *pattern);
    void setAppender(Appender* appender);
    void setLevel(LEVEL level); 
    void setName(const char *name);
    void setMaxLength(int length);

    void log(LEVEL level, const char * fmt, ...);
    void log(LEVEL level,const char * file, int line, const char * fmt, ...);

  private:
    LEVEL level_;
    Layout layout_;
    std::string name_;
    int maxLength_;

  private:
    Logger(const Logger&);
    void operator=(const Logger&);
};

}  // namespace logger
#endif  // _LOGGER_H_

