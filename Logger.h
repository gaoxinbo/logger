// File: logger.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LOGGER_H_
#define _LOGGER_H_

#include "Appender.h"
#include "Layout.h"

namespace logger {

enum LEVEL {
  kFATAL = 0,
  kERROR,
  kWARN,
  kINFO,
  kDEBUG,
  kLEVEL_LENGTH,
};

static const char * LevelMsg [kLEVEL_LENGTH] = {
  "FATAL",
  "ERROR",
  "WARN",
  "INFO",
  "DEBUG",
};

class Logger {
  public:
    Logger();
    ~Logger();

    void setAppender(Appender* appender);
    void setLevel(LEVEL level); 

    void log(LEVEL level, const char * fmt, ...);
    void log(LEVEL level,const char * file, int line, const char * fmt, ...);
  private:
    LEVEL level_;
    Layout layout_;

  private:
    Logger(const Logger&);
    void operator=(const Logger&);
};

}  // namespace logger
#endif  // _LOGGER_H_
