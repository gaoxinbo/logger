// File: Layout.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _LAYOUT_H_
#define _LAYOUT_H_

#include <vector>
#include <string>
#include "Appender.h"
#include "Component.h"

namespace logger {

class Component;

class Layout {
  public:
    Layout();
    ~Layout();

    std::string getPattern();
    void setPattern(const char *pattern); 
    void setAppender(Appender * appender);
    void append(const char * logname, LEVEL level, const char *msg);
    void append(const char *file, int line, const char * logname, LEVEL level, const char *msg);
    const std::vector<Component *> & getComponent() const;

  private:
    Appender * appender_;
    std::vector<Component *> component_;
    std::string pattern_;

  private:
    Layout(const Layout&);
    void operator=(const Layout&);

    void append(const LogEvent &le);
    void destroy();
};

}  // namespace logger
#endif  // _LAYOUT_H_

