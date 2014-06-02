// File: StringUtil.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-06-02
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _STRINGUTIL_H_
#define _STRINGUTIL_H_

#include <string>

namespace logger {

class StringUtil {
  public:
    StringUtil();
    ~StringUtil();

    static std::string trim(const std::string &s);
    static bool split(const std::string &s, std::string &key, std::string &value);

  private:
    StringUtil(const StringUtil&);
    void operator=(const StringUtil&);
};

}  // namespace logger
#endif  // _STRINGUTIL_H_

