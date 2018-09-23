/*
 *  FileName: pidController.cpp
 *  Copyright 2018 KrishnaBhatu and bhargav-umd
 *  @date Created on: Sep 20, 2018
 *  @author Author: [Driver]KrishnaBhatu [Navigator]bhargav-umd
 *  @brief  Description: This is the implementation of
 *                       PID controller class.
 */
#include<iostream>
#include "pidController.h"
PidController::PidController() {
}
/// @brief This constructor when called initializes
///        the PID parameters
/// @param propConst This is the Kp value
/// @param derivConst This is the Kd value
/// @param integralConst This is the Ki value
PidController::PidController(double propConst, double derivConst,
                             double integralConst) {
}
PidController::~PidController() {
  std::cout << "Class is destroyed\n";
}
/// @brief This function calculates the final velocity
///        using the initial velocity and the disance
/// @param x This is the initial velocity
/// @param y This is the final velocity
/// @return The function returns the final velocity
double PidController::calVelocity(double setVel, double actVel) {
  return 0;
}

