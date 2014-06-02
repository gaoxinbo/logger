#include "gtest/gtest.h"
#include "StringUtil.h"

using namespace logger;
using namespace std;

TEST(StringUtil,trim) {
  EXPECT_TRUE(StringUtil::trim("hello")=="hello");
  EXPECT_TRUE(StringUtil::trim(" hello")=="hello");
  EXPECT_TRUE(StringUtil::trim("hello ")=="hello");
  EXPECT_TRUE(StringUtil::trim(" hello ")=="hello");
}

TEST(Config,split) {
  string s = "key=value";
  string key;
  string value;
  EXPECT_TRUE(StringUtil::split(s,key,value)); 
  EXPECT_TRUE(key=="key");
  EXPECT_TRUE(value=="value");
  EXPECT_FALSE(StringUtil::split("key value",key,value)); 
}
