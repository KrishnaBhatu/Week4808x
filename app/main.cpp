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
  *  @file    main.cpp
  *  @author  Krishna Bhatu
  *
  *  @brief main code
  *
  *  @section DESCRIPTION
  *
  *  Source code for the main function, this demonstrates the working of the 
  *  PID controller and also implements the check function from a service class
  *  (NewVal) which demonstrates the implementation of the GoogleMock.
  */
#include<iostream>
#include "../include/pidController.h"
#include "../include/newVal.h"
int main() {
  double setVelocity, actualVelocity, kp, kd, ki;
  std::cout << "Enter the initial velocity: ";
  std::cin >> actualVelocity;
  std::cout << "Enter the set-point velocity: ";
  std::cin >> setVelocity;
  std::cout << "Enter Kp value: ";
  std::cin >> kp;
  std::cout << "Enter Kd value: ";
  std::cin >> kd;
  std::cout << "Enter Ki value: ";
  std::cin >> ki;
  bool flag;
  /// Creates the service object
  NewVal nd;
  /// Initialises the PID class object with reference to the service object.
  PidController carAB(&nd);
  PidController car(kp, kd, ki);
  double v = actualVelocity;
  std::cout << actualVelocity << std::endl;
  while (1) {
    v = car.calVelocity(setVelocity, actualVelocity);
    actualVelocity += v;
    std::cout << actualVelocity << std::endl;
    if ((actualVelocity - setVelocity < 0.001) &&
        (actualVelocity - setVelocity > - 0.001))
      break;
  }
  flag = carAB.velWithAddAPI(actualVelocity, setVelocity);
  std::cout << flag << std::endl;
  std::cout << carAB.velWithAddAPI(10.0, 10.0) << std::endl;
  return 0;
}
