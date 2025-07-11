#include <iostream>
#include "PID.H"
using namespace std;

int main() {
    PID pidObj = PID(0.1, 0, 0.5);

    double curr = 0.0;
    double dt = 0.5;
    for (int i = 0; i < 20; ++i) {
        double out = pidObj.compute(10, curr, dt);
        printf("curr:% 7.3F out:% 7.3F \n", curr, out);
        curr += out * dt;

    }

    return 0;


}