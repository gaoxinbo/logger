// File: FileAppender.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2014-05-25
// Copyright 2014, Xinbo Gao.  All rights reserved.

#ifndef _FILEAPPENDER_H_
#define _FILEAPPENDER_H_
namespace logger {

class FileAppender {
  public:
    FileAppender();
    ~FileAppender();

  private:
    FileAppender(const FileAppender&);
    void operator=(const FileAppender&);
};

}  // namespace logger
#endif  // _FILEAPPENDER_H_

