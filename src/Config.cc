// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include "Config.h"
#include <fstream>

using namespace std;

namespace logger {

Config::Config() {
}

Config::~Config() {
}

void Config::parse(const string &s) {
    string line = trim(s);
    string key,value;
    if(line.length()==0 || line[0] == '#' || split(line,key,value)==false )
      return;
    group(key,value);
}

void Config::parse(const char * filename) {
  ifstream ifile(filename);
  if(!ifile)
    return;

  string line;
  while(getline(ifile,line)) {
    parse(line);
  }
}

void Config::group(const string &key, const string &value) {
  string::size_type pos = key.find_first_of(".");
  if(pos==string::npos)
    return;

  string group_key = key.substr(0,pos);
  string k = key.substr(pos+1); 

  group_[group_key][k] = value;
  group(k,value);
}

map<string,string> Config::getGroup(const char * group) {
  return group_[group];
}

string Config::trim(const string &s){
  string::size_type first,last; 
  first = last = 0;
  first = s.find_first_not_of(" ");
  last = s.find_last_not_of(" ");
  if(first == string::npos || last == string::npos)
    return "";

  return s.substr(first,last-first+1);
}

bool Config::split(const string &s, string &key, string &value){
  string::size_type pos = 0;
  pos=s.find_first_of("=");
  if(pos==string::npos)
    return false;

  key = s.substr(0,pos);
  value = s.substr(pos+1);
  return true;
}

}  // namespace logger

