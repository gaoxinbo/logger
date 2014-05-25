#ifndef _LAYOUT_H
#define _LAYOUT_H

#include "Appender.h"

namespace logger {

class Layout{
  public:
    Layout();
    ~Layout();

    void setAppender(Appender * appender);
    void append(const char * level, const char *msg);
    void append(const char *file, int line,const char * level, const char *msg);

  private:
    Appender * appender_;
};

}

#endif

