/*
 *  @file test.cpp
 *  Copyright [2018] KrishnaBhatu and bhargav-umd
 *  @date Sep 20, 2018
 *  @author [Driver] KrishnaBhatu [Navigator] bhargav-umd
 *  @brief This is the declaration of test class.
 */

#include<gtest/gtest.h>
#include"pidController.h"

PidController test1(0.1, 0.01, 0.5);

TEST(PidControllerTest, PIDAlgoTest) {
  EXPECT_EQ(2.5, test1.calVelocity(60, 50));
  EXPECT_EQ(0.75, test1.calVelocity(60, 55));
}

TEST(PidControllerTest, PIDinit) {
  PidController test2(0.1, 0.01, 0.5);
  EXPECT_EQ(0, test2.errorPrevious);
  EXPECT_EQ(0, test2.result);
}
