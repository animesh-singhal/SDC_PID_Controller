#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  
  this->p_error = 0;
  this->i_error = 0;   // This is necessary. Other error init are due to formality
  this->d_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  double prev_cte = this->p_error;   //This captures the cte for the previous iteration
  
  this->p_error = cte;         
  this->i_error += cte;             // Integral term sums over all the integral terms
  this->d_error = cte - prev_cte;   //Assuming det(time)=1


}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  
  double steer = -1 * (Kp*p_error + Ki*i_error + Kd*d_error); 
  
  
  return steer;  // TODO: Add your total error calc here!
}