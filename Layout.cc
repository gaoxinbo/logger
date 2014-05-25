// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "Layout.h"
namespace logger {

Layout::Layout(){
  appender_ = NULL;
}

Layout::~Layout(){
  delete appender_;
  appender_ = NULL;
}


void Layout::setAppender(Appender * appender){
  appender_ = appender;
}

void Layout::append(const char * level, const char *msg){
  if(appender_ == NULL)
    return;

  char buf[1124]; 
  time_t now = time(NULL);
  tm  t;
  localtime_r(&now,&t);
  int n = strftime(buf,1124,"%Y-%m-%d %H:%M:%S ",&t);
  n += snprintf(buf+n,1124-n,"%-5s ",level);
  snprintf(buf+n,1124-n,"%s\n",msg);
  appender_->append(buf);

}

void Layout::append(const char *file, int line, const char * level, const char *msg){
  if(appender_ == NULL)
    return;

  char buf[1124]; 
  memset(buf,1124,0);
  time_t now = time(NULL);
  tm * t = new tm;
  localtime_r(&now,t);
  int n = strftime(buf,40,"%Y-%m-%d %H:%M:%S ",t);
  n += snprintf(buf+n,1124-n,"%-5s ",level);
  n += snprintf(buf+n,1124-n,"%s:%d ",file,line);
  snprintf(buf+n, 1124-n,"%s\n", msg);
  appender_->append(buf);

  delete t;
  t = NULL;
}


}  // namespace logger

