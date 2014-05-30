// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdarg.h>
#include <stdio.h>
#include <string>

#include "Logger.h"

namespace logger {

Logger::Logger(){
  level_ = kINFO;
  name_ = "ROOT";
  maxLength_ = 1024;
}

Logger::Logger(const char *name){
  level_ = kINFO;
  name_ = name;
  maxLength_ = 1024;
}

Logger::~Logger(){
}

void Logger::setAppender(Appender* appender){
  layout_.setAppender(appender);
}

void Logger::setLevel(LEVEL level){
  level_ = level;
}

void Logger::setPattern(const char *pattern) {
  layout_.setPattern(pattern);
}

void Logger::setName(const char *name) {
  name_ = name;
} 

void Logger::setMaxLength(int length) {
  maxLength_ = length;
}

void Logger::log(LEVEL level, const char * fmt, ...){
  if(level>level_ )
    return;

  va_list ap;
  va_start(ap,fmt);
  // in most case, 1024 is big enough
  char buf[maxLength_+1];
  memset(buf,maxLength_,0);
  vsnprintf(buf,maxLength_,fmt,ap);
  va_end(ap);

  layout_.append(name_.c_str(),level,buf);

}

void Logger::log(LEVEL level, const char * file, int line, const char *fmt, ...){
  if(level>level_)
    return;

  va_list ap;
  va_start(ap,fmt);
  // in most case, 1024 is big enough
  char buf[maxLength_+1];
  memset(buf,maxLength_,0);
  vsnprintf(buf,maxLength_,fmt,ap);
  va_end(ap);

  layout_.append(file,line,name_.c_str(),level,buf);

}


}  // namespace logger

