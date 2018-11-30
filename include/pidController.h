/*
 *  @file pidController.h
 *  Copyright [2018] KrishnaBhatu and bhargav-umd
 *  @date Sep 20, 2018
 *  @author [Driver] KrishnaBhatu [Navigator] bhargav-umd
 *  @brief This is the declaration of PID controller class.
 */
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
  *  @file    pidController.h
  *  @author  Krishna Bhatu
  *
  *  @brief PID Controller
  *
  *  @section DESCRIPTION
  *
  *  Source code for class declaration of the PID Controller
  */
#ifndef KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_
#define KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_

#include <iostream>
#include "newVal.h"

/*
 * @brief This is the class for implementing PID algorithm
 */

class PidController {
 private:
  double kp;
  double kd;
  double ki;
  ///Declaration of service(API) class object pointer 
  NewVal* newValCal;

 public:
  double errorPrevious;
  double result;

  /*
   * @brief This is the constructor for the class
   */
  PidController();
  /*
   * @brief It is a constructor that initialises the object with the object
   *        pointer given by the object definition.
   */
  explicit PidController(NewVal* newval)
             : newValCal(newval),
               kp(0.1),
               kd(0.01),
               ki(0.5),
               errorPrevious(0),
               result(0){
  } 
  /*
   *  @brief This is also a constructor, but it also defines the gain parameters
   *
   *  @param First parameter is KP value
   *  @param Second parameter is KD value
   *  @param Third parameter is KI value
   */
  PidController(double, double, double);

  /*
   *  @brief This is the destructor for the class
   */
  ~PidController();

  /*
   * @brief This is a method to calculate the final velocity
   *
   * @param First parameter is the set-point (final) velocity
   * @param Second parameter is the actual (initial) velocity
   *
   * @return It returns a velocity update value
   */
  double calVelocity(double, double);
  /// Method to chech is the Desired Velocity is acheved or not.
  bool velWithAddAPI(double calVal, double desVal);
};

#endif  // KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_
