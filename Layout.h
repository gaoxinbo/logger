// File: Layout.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LAYOUT_H_
#define _LAYOUT_H_

#include "Appender.h"

namespace logger {

class Layout {
  public:
    Layout();
    ~Layout();

    void setAppender(Appender * appender);
    void append(const char * level, const char *msg);
    void append(const char *file, int line,const char * level, const char *msg);

  private:
    Appender * appender_;

  private:
    Layout(const Layout&);
    void operator=(const Layout&);
};

}  // namespace logger
#endif  // _LAYOUT_H_

