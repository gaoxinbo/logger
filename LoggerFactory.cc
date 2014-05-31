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
    logger_[name] = new Logger(name);
  }
  return logger_[name];
}

void LoggerFactory::putLogger(const char *name, Logger *logger){
  if(logger_.find(name) != logger_.end()) {
    // delete old one
    delete (*logger_.find(name)).second;
    logger_.erase(name);
  }
  logger_[name] = logger;
}

void LoggerFactory::init(const char *filename) {
}

}  // namespace logger

