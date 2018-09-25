/** @file main.cpp
* @brief This is a program to find resultant velocity implementing PID controller.
*
* Copyright [2018] Ashwin Goyal (driver), Indushekhar Prasad Singh (navigator)
* Created on: Sep 25, 2018
*/

#include <pidController.h>

/**
* @brief main function takes input from the user to compute the new velocity
*
* @return an integer output just to avoid a warning
*/

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

  return 0;
}
