#include <vector>
#include "gtest/gtest.h"
#include "Layout.h"

using namespace std;
using namespace logger;


TEST(Layout,init) {
  Layout layout;
  EXPECT_TRUE(layout.getPattern() == "%t %l %f %m");

  // test default pattern
  vector<Component *> vec = layout.getComponent();
  EXPECT_TRUE(vec.size() == 4);

  EXPECT_TRUE(vec[0]->getName() == "TimeComponent");
  EXPECT_TRUE(vec[1]->getName() == "LevelComponent");
  EXPECT_TRUE(vec[2]->getName() == "FileComponent");
  EXPECT_TRUE(vec[3]->getName() == "MsgComponent");


  // test customise pattern with illegal name
  layout.setPattern("%t %l %m %g %f %n %p %T");
  EXPECT_TRUE(layout.getPattern() == "%t %l %m %g %f %n %p %T");

  vec = layout.getComponent();
  EXPECT_TRUE(vec.size() == 7);
  EXPECT_TRUE(vec[0]->getName() == "TimeComponent");
  EXPECT_TRUE(vec[1]->getName() == "LevelComponent");
  EXPECT_TRUE(vec[2]->getName() == "MsgComponent");
  EXPECT_TRUE(vec[3]->getName() == "FileComponent");
  EXPECT_TRUE(vec[4]->getName() == "LogNameComponent");
  EXPECT_TRUE(vec[5]->getName() == "PidComponent");
  EXPECT_TRUE(vec[6]->getName() == "TidComponent");
}
