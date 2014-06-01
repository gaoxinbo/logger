// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "LoggerFactory.h"
#include "ConsoleAppender.h"
#include "FileAppender.h"

using namespace std;
namespace logger {

map<const char *, Logger *> LoggerFactory::logger_;
Config LoggerFactory::config_;

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
  config_.parse(filename);
  // get all logger name
  map<string,string> m = config_.getGroup("logger");
  if(m.find("rootCategory") != m.end()) {
    string names = m["rootCategory"];
    names = config_.trim(names);
    string::size_type pos,pre;
    pos = pre = 0;
    while( (pos = names.find_first_of(",",pre)) != string::npos) { 
      string name = names.substr(pre,pos-pre);
      initLogger(name.c_str());
      pos = ++pre;
    }
    string name = names.substr(pos);
    initLogger(name.c_str());
  }
}

void LoggerFactory::initLogger(const char *name) {
  if(logger_.find(name) != logger_.end())
    return;

  // create logger
  map<string,string> m = config_.getGroup(name);
  Logger * logger = new Logger(name);
  logger_[name] = logger;

  // set appender
  Appender * appender = NULL;
  string appender_item = name;
  appender_item += ".appender";
  if(m.find(appender_item) != m.end()) {
    if(m[appender_item] == "FileAppender") {
      FileAppender *appender = new FileAppender();
      string filename = m[appender_item+".filename"];
      if(filename != "")
        appender->setFileName(filename.c_str());

      string timer = m[appender_item+".timer"];
      if(timer != ""){
        appender->setTimer(atoi(timer.c_str()));
      }

    }
    else if(m[appender_item]== "ConsoleAppender" ){
      Appender *appender = new ConsoleAppender();
    }
  }

  // use ConsuleAppender by default
  if(appender == NULL)
    appender = new ConsoleAppender();
  logger->setAppender(appender);

  // set pattern 
  string pattern_item = name;
  pattern_item += ".pattern";
  if(m.find(pattern_item) != m.end()) {
    string item = m[pattern_item];
    logger->setPattern(item.c_str());
  }

  // set max length
  string length_item = name;
  length_item += ".maxlength";
  if(m.find(length_item) != m.end()) {
    string len = m[length_item];
    logger->setMaxLength(atoi(len.c_str()));
  }

  // set level, hard code for now
  string level_item = name;
  level_item += ".level";
  string level = "INFO";
  if(m.find(level_item) != m.end()) {
    level = m[level_item];
  }

  if(level == "FATAL")
    logger->setLevel(kFATAL);
  else if(level == "ERROR") 
    logger->setLevel(kERROR);
  else if(level == "WARN") 
    logger->setLevel(kWARN);
  else if(level == "INFO") 
    logger->setLevel(kINFO);
  else if(level == "DEBUG") 
    logger->setLevel(kDEBUG);

 }

}  // namespace logger

