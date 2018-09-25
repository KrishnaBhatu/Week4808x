/*
 *  @file pidController.h
 *  Copyright [2018] KrishnaBhatu and bhargav-umd
 *  @date Sep 20, 2018
 *  @author [Driver] KrishnaBhatu [Navigator] bhargav-umd
 *  @brief This is the declaration of PID controller class.
 */

#ifndef KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_
#define KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_

#include<iostream>

/*
 * @brief This is the class for implementing PID algorithm
 */

class PidController {
 private:
  double kp;
  double kd;
  double ki;

 public:
  double errorPrevious;
  double result;

  /*
   * @brief This is the constructor for the class
   */
  PidController();

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
};

#endif  // KRISHNA_WEEK4808X_INCLUDE_PIDCONTROLLER_H_
