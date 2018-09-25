/*
 * @file pidController.cpp
 * @Copyright [2018] Ashwin Goyal [Driver], Indushekhar Prasad Singh [Navigator]
 * @date Sep 25, 2018
 * @brief This is the implementation of PID controller class.
 */

#include <pidController.h>

/*
 * @brief This is an empty constructor
 */
PidController::PidController() {
  this->kp = 0;
  this->kd = 0;
  this->ki = 0;
  result = 0;
  errorPrevious = 0;
}

/*
 * @brief This constructor when called initializes the PID parameters
 *
 * @param propConst This is the Kp value
 * @param derivConst This is the Kd value
 * @param integralConst This is the Ki value
 */
PidController::PidController(double propConst, double derivConst,
                             double integralConst) {
  this->kp = propConst;
  this->kd = derivConst;
  this->ki = integralConst;
  result = 0;
  errorPrevious = 0;
}

/*
 *  @brief This is the destructor for the class
 */
PidController::~PidController() {
  std::cout << "Class is destroyed" << std::endl;
}

/* @brief This function calculates the final velocity using the initial velocity and set-point velocity
 *
 * @param First parameter is the final velocity
 * @param Second parameter is the initial velocity
 *
 * @return The function returns the velocity update
 */
double PidController::calVelocity(double setVel, double actVel) {
  double KP = this->kp;
  double KD = this->kd;
  double KI = this->ki;
  double error = setVel - actVel;

  // This parameters limits the PID parameter
  double max = 100, min = -100;
  double changeTime = 0.1;

  // Proportional term
  double P = KP * error;

  // Integral term
  double integralTerm = this->result;
  integralTerm += error * changeTime;
  double I = KI * integralTerm;

  // Derivative term
  double derivativeTerm;
  derivativeTerm = (error - errorPrevious) / changeTime;
  double D = KD * derivativeTerm;

  // Calcuation of PID parameter
  double newVel = P + D + I;

  // Limiting condition for over and under shooting
  if (newVel > max)
    newVel = max;
  if (newVel < min)
    newVel = min;

  // Updating error value
  errorPrevious = error;
  result = integralTerm;

  return newVel;
}
