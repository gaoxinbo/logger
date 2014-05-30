#include "Logger.h"
#include "ConsoleAppender.h"
#include "FileAppender.h"

#include "time.h"
#include <iostream>
using namespace std;
using namespace logger;

int main(){
  //ConsoleAppender * appender = new ConsoleAppender();
  FileAppender * appender = new FileAppender();
  appender->setFileName("test"); 
  appender->setTimer(1800);

  Logger * logger = new Logger();
  logger->setAppender(appender);
  logger->log(kINFO,"hello world");
  logger->log(kINFO,__FILE__,__LINE__,"hello world");
  logger->log(kDEBUG,__FILE__,__LINE__,"hello world");
  logger->log(kWARN,__FILE__,__LINE__,"hello world");
  logger->log(kERROR,__FILE__,__LINE__,"hello world");
  logger->log(kFATAL,__FILE__,__LINE__,"hello world");
  logger->setPattern("%t %n %T %p %l %m");
  logger->log(kINFO,"hello world");
  logger->log(kINFO,__FILE__,__LINE__,"hello world");
  logger->log(kDEBUG,__FILE__,__LINE__,"hello world");
  logger->log(kWARN,__FILE__,__LINE__,"hello world");
  logger->log(kERROR,__FILE__,__LINE__,"hello world");
  logger->log(kFATAL,__FILE__,__LINE__,"hello world");

  return 0;
}

