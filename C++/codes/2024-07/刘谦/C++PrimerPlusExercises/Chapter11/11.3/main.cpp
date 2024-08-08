#include <iostream>
#include "vector.h"
#include <cstdlib>     
#include <ctime>  
#include <climits>     

int main() {
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));     

    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps;
    double target;
    double dstep;
    int numTests;

    cout << "Enter the number of tests: ";
    cin >> numTests;

    cout << "Enter target distance (q to quit): ";
    while (cin >> target) {
        cout << "Enter step length: ";
        if (!(cin >> dstep))
            break;

        unsigned long maxSteps = 0;
        unsigned long minSteps = ULONG_MAX;
        unsigned long totalSteps = 0;

        for (int i = 0; i < numTests; ++i) {
            result.reset(0.0, 0.0);
            steps = 0;
            while (result.magval() < target) {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }

            if (steps > maxSteps)
                maxSteps = steps;
            if (steps < minSteps)
                minSteps = steps;
            totalSteps += steps;
        }

        cout << "After " << numTests << " tests:\n";
        cout << "Maximum steps: " << maxSteps << endl;
        cout << "Minimum steps: " << minSteps << endl;
        cout << "Average steps: " << (double)totalSteps / numTests << endl;

        cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye!\n";
    return 0;
}
