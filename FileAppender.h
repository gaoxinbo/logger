#ifndef _FILE_APPENDER_H
#define _FILE_APPENDER_H

#include "Appender.h"
namespace logger {

class FileAppender : public Appender {
  public:
    FileAppender();
    virtual ~FileAppender();
    virtual void append(const char *msg);
};

}

#endif

