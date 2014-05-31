// File: LoggerFactory.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-29
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LOGGERFACTORY_H_
#define _LOGGERFACTORY_H_

#include <map>
#include "Logger.h"
#include "Config.h"

namespace logger {

class LoggerFactory {
  public:
    LoggerFactory();
    ~LoggerFactory();

    static Logger* getLogger(const char *);
    static void putLogger(const char *name , Logger * logger);
    static void init(const char *filename);
  private:
    LoggerFactory(const LoggerFactory&);
    void operator=(const LoggerFactory&);

    static void initLogger(const char *name);
    static std::map<const char *, Logger *> logger_;
    static Config config_;
};

}  // namespace logger
#endif  // _LOGGERFACTORY_H_

