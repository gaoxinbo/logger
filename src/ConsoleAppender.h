// File: ConsoleAppender.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _CONSOLEAPPENDER_H_
#define _CONSOLEAPPENDER_H_

#include "Appender.h"

namespace logger {

class ConsoleAppender : public Appender {
  public:
    ConsoleAppender();
    virtual ~ConsoleAppender();

    virtual void append(const char * msg);

  private:
    ConsoleAppender(const ConsoleAppender&);
    void operator=(const ConsoleAppender&);
};

}  // namespace logger
#endif  // _CONSOLEAPPENDER_H_

