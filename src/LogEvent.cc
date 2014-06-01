// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdio.h>
#include "LogEvent.h"

namespace logger {

LogEvent::LogEvent() {
  file_ = NULL;
  msg_ = NULL;
}

LogEvent::~LogEvent() {
}

}  // namespace logger

