// File: Config.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-31
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include <map>

namespace logger {

class Config {
  public:
    Config();
    ~Config();

    void parse(const char *filename);
    void parse(const std::string &s);
    std::map<std::string,std::string> getGroup(const char *group);

    std::string trim(const std::string &s);
    bool split(const std::string &s, std::string &key, std::string &value);
    void group(const std::string &key, const std::string &value);
  private:
    std::map<std::string,std::map<std::string,std::string> > group_;

  private:
    Config(const Config&);
    void operator=(const Config&);

};

}  // namespace logger
#endif  // _CONFIG_H_

