// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "Layout.h"
#include "ConsoleAppender.h"

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
  pattern_ = "";
  vector<Component *>::iterator it = component_.begin();
  for(; it!=component_.end(); ++it){
    delete *it;
  }
  component_.clear();

}


string Layout::getPattern(){
  return pattern_;
}

void Layout::setPattern(const char * pattern){
  // destroy first
  destroy();

  pattern_ = pattern;
  // %t time
  // %l level
  // %f file position 
  // %m message
  // %n log name 
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
          case 'n':
            component_.push_back(new LogNameComponent()); 
            break;
          case 'p':
            component_.push_back(new PidComponent()); 
            break;
          case 'T':
            component_.push_back(new TidComponent()); 
            break;
        }
        i++;
      }
    }
  }
  
}

void Layout::setAppender(Appender * appender){
  if(appender_ != NULL)
    delete appender_;
  appender_ = appender;
}

void Layout::append(const char * logname,LEVEL level, const char *msg){
  append(NULL,0,logname,level,msg);
}

void Layout::append(const char *file, int line, const char * logname, LEVEL level, const char *msg){
  if(appender_ == NULL) {
    // set default appender;
    appender_ = new ConsoleAppender();
  }

  LogEvent le;
  le.file_ = file;
  le.line_ = line;
  le.level_ = level;
  le.msg_ = msg;
  le.logName_ = logname;
  append(le);
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

