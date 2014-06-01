// File: Level.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-28
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LEVEL_H_
#define _LEVEL_H_

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

}  // namespace logger
#endif  // _LEVEL_H_

