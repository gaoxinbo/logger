// File: LoggerFactory.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-29
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LOGGERFACTORY_H_
#define _LOGGERFACTORY_H_

#include "Logger.h"

namespace logger {

class LoggerFactory {
  public:
    LoggerFactory();
    ~LoggerFactory();

    static Logger* getLogger(const char *);
  private:
    LoggerFactory(const LoggerFactory&);
    void operator=(const LoggerFactory&);
};

}  // namespace logger
#endif  // _LOGGERFACTORY_H_

