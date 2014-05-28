// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdarg.h>
#include <stdio.h>
#include <string>

#include "Logger.h"

namespace logger {

Logger::Logger(){
  level_ = kINFO;
}

Logger::~Logger(){
}

void Logger::setAppender(Appender* appender){
  layout_.setAppender(appender);
}

void Logger::setLevel(LEVEL level){
  level_ = level;
}

void Logger::log(LEVEL level, const char * fmt, ...){
  if(level>level_ )
    return;

  va_list ap;
  va_start(ap,fmt);
  // in most case, 1024 is big enough
  char buf[1024];
  vsnprintf(buf,1024,fmt,ap);
  va_end(ap);

  layout_.append(level,buf);

}

void Logger::log(LEVEL level, const char * file, int line, const char *fmt, ...){
  if(level>level_)
    return;

  va_list ap;
  va_start(ap,fmt);
  // in most case, 1024 is big enough
  char buf[1024];
  memset(buf,1024,0);
  vsnprintf(buf,1024,fmt,ap);
  va_end(ap);

  layout_.append(file,line,level,buf);

}


}  // namespace logger

