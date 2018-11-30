/**
  * BSD 3-Clause License
  * Copyright (c) 2018, KrishnaBhatu
  * All rights reserved.
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions are met:
  *
  * Redistributions of source code must retain the above copyright notice, this
  * list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * Neither the name of the copyright holder nor the names of its
  * contributors may be used to endorse or promote products derived from
  * this software without specific prior written permission.
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *  @copyright (c) BSD
  *  @file    test.cpp
  *  @author  Krishna Bhatu
  *
  *  @brief This is the declaration of test class. 
  */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../include/pidController.h"
#include "../include/newVal.h"

using ::testing::Return;
using ::testing::_;
using ::testing::AtLeast;

/// Creating the PID object
PidController test1(0.1, 0.01, 0.5);
/// Creating the chile of service NewVal
class Mocktest : public NewVal {
 public:
  MOCK_METHOD2(checkResult, bool(double calVel, double desVel));
};

/// Test for checking the PID algorithm
TEST(PidControllerTest, PIDAlgoTest) {
  EXPECT_EQ(2.5, test1.calVelocity(60, 50));
  EXPECT_EQ(0.75, test1.calVelocity(60, 55));
}

/// Test for checking proper initialisation
TEST(PidControllerTest, PIDinit) {
  PidController test2(0.1, 0.01, 0.5);
  EXPECT_EQ(0, test2.errorPrevious);
  EXPECT_EQ(0, test2.result);
}

/// Test of the service using the mock class
TEST(PidControllerTest, APITest) {
  Mocktest mockobj;
  EXPECT_CALL(mockobj, checkResult(_, _)).Times(AtLeast(1));
  PidController pidObj(&mockobj);
  EXPECT_FALSE(pidObj.velWithAddAPI(30.0, 40.0));
}

