// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "LoggerFactory.h"
using namespace std;
namespace logger {

map<const char *, Logger *> LoggerFactory::logger_;

LoggerFactory::LoggerFactory() {
}

LoggerFactory::~LoggerFactory() {
}

Logger * LoggerFactory::getLogger(const char *name) {
  if(logger_.find(name) == logger_.end()){
    logger_[name] = new Logger();
  }
  return logger_[name];
}

}  // namespace logger

