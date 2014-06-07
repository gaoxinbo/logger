// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "Appender.h"
using namespace std;

namespace logger {

Appender::Appender() {
} 

Appender::~Appender() {
}

string Appender::getName() {
  return name_;
}

void Appender::setName(string name) {
  name_ = name; 
}

}  // namespace logger

