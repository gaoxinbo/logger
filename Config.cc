// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "Config.h"

using namespace std;

namespace logger {

Config::Config() {
}

Config::~Config() {
}

void Config::parse(const char * filename) {
}

map<string,string> Config::getGroup(const char * group) {
  return map_[group];
}

}  // namespace logger

