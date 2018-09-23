/*
 *  FileName: pidController.h
 *  Copyright 2018 KrishnaBhatu and bhargav-umd
 *  @date Created on: Sep 20, 2018
 *  @author Author: [Driver]KrishnaBhatu [Navigator]bhargav-umd
 *  @brief  Description: This is the declaration of
 *                       PID controller class.
 */

#ifndef INCLUDE_PIDCONTROLLER_H_
#define INCLUDE_PIDCONTROLLER_H_

#include<iostream>
/// @brief This is the class for implementing PID algorithm
class PidController {
 private:
  double kp;
  double kd;
  double ki;
 public:
  double errorPrevious;
  double result;
  PidController();
  /// @param First parameter is KP value
  /// @param Second parameter is KD value
  /// @param Third parameter is KI value
  PidController(double, double, double);
  ~PidController();
  /// @param Setpoint velocity
  /// @param Actual velocity
  /// @return Velocity Update
  double calVelocity(double, double);
};




#endif /* PIDCONTROLLER_H_ */

