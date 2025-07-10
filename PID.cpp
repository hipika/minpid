#include <iostream>
#include "PID.H"
using namespace std;

PID::PID(double Kp, double Ki, double Kd) {
    this->Kp = Kp; // similar to self in pythons
    this->Ki = Ki;
    this->Kd = Kd;
    this->integral = 0.0;
    this->prevError = 0.0;
};

double PID::compute(double setpoint, double current_value, double dt) {
    double error = setpoint - current_value;
    double Pout = Kp * error;
    
    integral += error * dt;
    double Iout = Ki * integral;

    double derivative = (error - prevError) / dt;
    double Dout = Kd * derivative;

    double output = Pout + Iout + Dout;

    return output;
};