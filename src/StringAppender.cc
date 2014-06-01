// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "StringAppender.h"

using namespace std;

namespace logger {

StringAppender::StringAppender() : Appender(){
}

StringAppender::~StringAppender() {
}

void StringAppender::append(const char *msg) {
  oss_<<msg;
}

const ostringstream & StringAppender::getStream() {
  return oss_;
}

void StringAppender::clear() {
  oss_.clear();
}

}  // namespace logger

