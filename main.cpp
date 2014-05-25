#include "Logger.h"
#include "ConsoleAppender.h"

#include "time.h"
#include <iostream>
using namespace std;
using namespace logger;

int main(){
  ConsoleAppender * appender = new ConsoleAppender();
  Logger * logger = new Logger();
  logger->setAppender(appender);
  logger->log(kINFO,"hello world");
  logger->log(kINFO,__FILE__,__LINE__,"hello world");
  logger->log(kDEBUG,__FILE__,__LINE__,"hello world");
  logger->log(kWARN,__FILE__,__LINE__,"hello world");
  logger->log(kERROR,__FILE__,__LINE__,"hello world");
  logger->log(kFATAL,__FILE__,__LINE__,"hello world");
  return 0;
}
