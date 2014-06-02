// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "StringUtil.h"
using namespace std;

namespace logger {

StringUtil::StringUtil() {
}

StringUtil::~StringUtil() {
}

string StringUtil::trim(const string &s){
  string::size_type first,last; 
  first = last = 0;
  first = s.find_first_not_of(" ");
  last = s.find_last_not_of(" ");
  if(first == string::npos || last == string::npos)
    return "";

  return s.substr(first,last-first+1);
}

bool StringUtil::split(const string &s, string &key, string &value){
  string::size_type pos = 0;
  pos=s.find_first_of("=");
  if(pos==string::npos)
    return false;

  key = s.substr(0,pos);
  value = s.substr(pos+1);
  return true;
}

}  // namespace logger

