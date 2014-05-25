/**
 *
 * @file logger.h
 * @author XinBo Gao
 * @date 2014-5-23
 * @version 1.0
 */

#ifndef _LOGGER_H
#define _LOGGER_H

#include "Layout.h"
#include "Appender.h"

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

class Logger{
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
};

}
#endif

