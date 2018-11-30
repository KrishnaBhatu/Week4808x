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
  *  @file    pidController.cpp
  *  @author  Krishna Bhatu
  *
  *  @brief PID Controller 
  *
  *  @section DESCRIPTION
  *
  *  Source code for the definition od a PID controller.
  */

#include "../include/pidController.h"
/*
 * @brief This constructor when called initializes the PID parameters
 *
 * @param propConst This is the Kp value
 * @param derivConst This is the Kd value
 * @param integralConst This is the Ki value
 */
PidController::PidController(double propConst, double derivConst,
                             double integralConst) {
  kp = propConst;
  kd = derivConst;
  ki = integralConst;
  result = 0;
  errorPrevious = 0;
  newValCal = nullptr;
}
/*
 *  @brief This is the destructor for the class
 */
PidController::~PidController() {
  std::cout << "Class is destroyed" << std::endl;
}
/* @brief This function calculates the final velocity using the initial velocity
 * and set-point velocity
 *
 * @param First parameter is the final velocity
 * @param Second parameter is the initial velocity
 *
 * @return The function returns the velocity update
 */
double PidController::calVelocity(double setVel, double actVel) {
  double KP = kp;
  double KD = kd;
  double KI = ki;
  double error = setVel - actVel;
  double changeTime = 0.1;

  // Proportional term
  double P = KP * error;

  // Integral term
  double integralTerm = result;
  integralTerm += error * changeTime;
  double I = KI * integralTerm;

  // Derivative term
  double derivativeTerm;
  derivativeTerm = (error - errorPrevious) / changeTime;
  double D = KD * derivativeTerm;

  // Calcuation of PID parameter
  double newVel = P + D + I;

  // Updating error value
  errorPrevious = error;
  result = integralTerm;

  return newVel;
}
/*
 * @brief This method is for the demonstration of the mock test, which is
 *        dependent on the server class of NewVal(this usually is an API which
 *        we want to test.
 *
 * @param calVal This is the calculated value after the PID controller 
 *               stabalizes
 * @param desVal This is the desired value that we want to achieve
 * @return test It reters a boolean depending on whether the desired value is
 *              achieved or not. 
 */

bool PidController::velWithAddAPI(double calVal, double desVal) {
  /// Calling the method of service class via the object pointer
  bool test = newValCal->checkResult(calVal, desVal);
  if (test) {
    std::cout << "Desired Value is Achieved" << std::endl;
  } else {
    std::cout << "Desired Value is NOT Achieved" << std::endl;
  }
  return test;
}


