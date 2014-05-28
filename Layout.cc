// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Layout.h"

using namespace std;
namespace logger {

Layout::Layout(){
  appender_ = NULL;
  // set default pattern;
  setPattern("%t %l %f %m");
}

Layout::~Layout(){
  delete appender_;
  appender_ = NULL;
  destroy();
}

void Layout::destroy(){
  vector<Component *>::iterator it = component_.begin();
  for(; it!=component_.end(); ++it){
    delete *it;
  }
  component_.clear();

}
void Layout::setPattern(const char * pattern){
  // destroy first
  destroy();
  // %t time
  // %l level
  // %f file position 
  // %m message
  int len = strlen(pattern);  
  for(int i=0; i<len; i++){
    if(pattern[i] == '%'){
      if(i+1<len){
        char c = pattern[i+1];
        switch(c){
          case 't':
            component_.push_back(new TimeComponent());
            break;
          case 'l':
            component_.push_back(new LevelComponent()); 
            break;
          case 'f':
            component_.push_back(new FileComponent()); 
            break;
          case 'm':
            component_.push_back(new MsgComponent()); 
            break;
        }
        i++;
      }
    }
  }
  
}

void Layout::setAppender(Appender * appender){
  appender_ = appender;
}

void Layout::append(LEVEL level, const char *msg){
  append(NULL,0,level,msg);
}

void Layout::append(const char *file, int line, LEVEL level, const char *msg){
  if(appender_ == NULL)
    return;

  LogEvent le;
  le.file_ = file;
  le.line_ = line;
  le.level_ = level;
  le.msg_ = msg;
  append(le);
  /*
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
  */
}

void Layout::append(const LogEvent &le){
  ostringstream oss;
  vector<Component *>::iterator it = component_.begin();
  for(; it!=component_.end(); ++it){
    (*it)->append(le,oss);
  } 
  oss<<endl;
  appender_->append(oss.str().c_str());
}

}  // namespace logger

