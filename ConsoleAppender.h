#ifndef _CONSOLE_APPENDER_H
#define _CONSOLE_APPENDER_H

#include "Appender.h"

namespace logger{

class ConsoleAppender : public Appender{
  public:
    ConsoleAppender();
    virtual ~ConsoleAppender();
    virtual void append(const char * msg);
};

}

#endif

