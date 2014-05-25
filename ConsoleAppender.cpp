#include <stdio.h>
#include "ConsoleAppender.h"

namespace logger {

ConsoleAppender::ConsoleAppender():Appender(){
}

ConsoleAppender::~ConsoleAppender(){
}

void ConsoleAppender::append(const char * msg){
  printf("%s\n", msg);
}

}

