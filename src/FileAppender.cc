// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <assert.h>
#include <string.h>
#include <sys/time.h>

#include "FileAppender.h"

using namespace std;

namespace logger {

FileAppender::FileAppender() : Appender(){
  fp_ = NULL;

  filename_ = "log"; 
  // default we switch file every 24 hours
  second_ = 3600*24;  
  time_t now = time(NULL);
  nextTime_ = now - now % second_;
}

FileAppender::~FileAppender() {
  fclose(fp_);
  fp_ = NULL;
}

void FileAppender::append(const char *msg) {
  if(fp_ == NULL)
    openFile();

  if(needSwitch())
    openFile();

  if(fp_ != NULL){
    fwrite(msg, strlen(msg),1,fp_);
  }
}

void FileAppender::setFileName(const char * filename) {
  filename_ = filename;
}

void FileAppender::setTimer(int second) {
  if(second==0)
    second_ = 3600*24;
  else
    second_ = second;
  time_t now = time(NULL);
  nextTime_ = now - now % second_;
}

bool FileAppender::needSwitch(){
  if(time(NULL) > nextTime_)
    return true;
  else
    return false;
}

void FileAppender::openFile(){
  if(fp_ != NULL){
    fclose(fp_);
    fp_ = NULL;
  }

  // open file just for appending content
  time_t now = time(NULL);
  assert(second_ != 0);
  now = now - (now % second_); 
  nextTime_ = now + second_;

  tm t;
  localtime_r(&now,&t);

  char buf[20];
  strftime(buf,30,"%Y%m%d%H%M", &t); 
  string name = filename_ + "_" + buf + ".log"; 
  //string name = filename_;
  fp_ = fopen(name.c_str(), "a");

}

}  // namespace logger

