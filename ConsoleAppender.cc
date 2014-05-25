// Copyright 2014, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdio.h>
#include "ConsoleAppender.h"
namespace logger {

ConsoleAppender::ConsoleAppender():Appender(){
}

ConsoleAppender::~ConsoleAppender(){
}

void ConsoleAppender::append(const char * msg){
  printf("%s", msg);
}


}  // namespace logger

