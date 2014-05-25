#ifndef _APPENDER_H
#define _APPENDER_H

namespace logger {

class Appender {
  public:
    Appender();
    virtual ~Appender() = 0; 
    virtual void append(const char *msg) = 0 ;
};
}

#endif

