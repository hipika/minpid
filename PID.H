#ifndef PID_H
#define PID_H

class PID {
    public:
        PID(double Kp, double Ki, double Kd);
        double compute(double setpoint, double current_value, double dt);
    protected:
    private: // controller needs to remember the values -> reused everytime compute is called
        double Kp, Ki, Kd; // gain coefficints - determine how aggressively P, I, and D react to the error
        double prevError; // derivative = (error - prevError) /dt
        /*
            This is the previous error that is stored so computation can be made to see how fast the error is changing
            P is the current error
            I is previous added
            D is how fast the rate is changing
        */
        double integral;

};

#endif