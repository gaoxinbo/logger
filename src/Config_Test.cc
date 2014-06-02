#include "gtest/gtest.h"
#include "Config.h"

using namespace logger;
using namespace std;

TEST(Config,trim) {
  Config config;
  EXPECT_TRUE(config.trim("hello")=="hello");
  EXPECT_TRUE(config.trim(" hello")=="hello");
  EXPECT_TRUE(config.trim("hello ")=="hello");
  EXPECT_TRUE(config.trim(" hello ")=="hello");
}

TEST(Config,split) {
  Config config;
  string s = "key=value";
  string key;
  string value;
  EXPECT_TRUE(config.split(s,key,value)); 
  EXPECT_TRUE(key=="key");
  EXPECT_TRUE(value=="value");
  EXPECT_FALSE(config.split("key value",key,value)); 
}
