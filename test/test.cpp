#include<gtest/gtest.h>
#include"pidController.h"

PidController test1(0.1, 0.01, 0.5);

TEST (PidControllerTest, PIDAlgoTest) {
  EXPECT_EQ(2.75, test1.calVelocity(60, 50));
  EXPECT_EQ(1.25, test1.calVelocity(60, 55));
}

TEST (PidControllerTest, PIDinit) {
  PidController test2();	
  EXPECT_EQ(0, test2.errorPrevious);
  EXPECT_EQ(0, test2.result);
}
