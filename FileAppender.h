// File: FileAppender.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _FILEAPPENDER_H_
#define _FILEAPPENDER_H_

#include <stdio.h>
#include <string>
#include "Appender.h"

namespace logger {

class FileAppender : public Appender {
  public:
    FileAppender();
    virtual ~FileAppender();

    virtual void append(const char *msg); 

    /**
     * set how long we switch a new log file
     */
    void setTimer(int second);

    /**
     * Actually, here we just set the prefix of the log file. 
     * For example, if the name is "hello" then the real file name is "hello_yyyy_hh_mm.log" 
     */
    void setFileName(const char * filename);
  private:
    FILE * fp_;
    int second_;
    int nextTime_;
    std::string filename_;

  private:
    FileAppender(const FileAppender&);
    void operator=(const FileAppender&);

    bool needSwitch();
    void openFile();
};

}  // namespace logger
#endif  // _FILEAPPENDER_H_

