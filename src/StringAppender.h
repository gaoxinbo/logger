// File: StringAppender.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-30
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _STRINGAPPENDER_H_
#define _STRINGAPPENDER_H_

#include "Appender.h"
#include <sstream>

namespace logger {

class StringAppender : public Appender {
  public:
    StringAppender();
    virtual ~StringAppender();

    virtual void append(const char *msg);
    const std::ostringstream & getStream();
    void clear();


  private:
    StringAppender(const StringAppender&);
    void operator=(const StringAppender&);
    std::ostringstream oss_;
};

}  // namespace logger
#endif  // _STRINGAPPENDER_H_

