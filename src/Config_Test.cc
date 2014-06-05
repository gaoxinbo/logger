#include "gtest/gtest.h"
#include "Config.h"
#include <iostream>

using namespace logger;
using namespace std;

TEST(Config,parseLine) {
  Config config;
  config.parseLine("logger.root");
  map<string,string> group = config.getGroup("logger");

  EXPECT_TRUE(group.size()==0);
  config.parseLine("#logger.root=1");
  group = config.getGroup("logger");
  EXPECT_TRUE(group.size()==0);
  config.parseLine("  #logger.root=1  ");
  group = config.getGroup("logger");
  EXPECT_TRUE(group.size()==0);

  config.parseLine("logger.root=value  ");
  group = config.getGroup("logger");
  EXPECT_TRUE(group.size()==1);

  EXPECT_TRUE(group.count("root")==1);
  EXPECT_TRUE(group["root"]=="value");
}

TEST(Config,parsefile) {
  Config config;
}
