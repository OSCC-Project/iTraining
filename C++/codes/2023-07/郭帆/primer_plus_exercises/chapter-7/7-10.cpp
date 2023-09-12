#include <iostream>

using namespace std;

typedef double (*operation_func)(double, double);

double add(double x, double y);
double sub(double x, double y);
double mul(double x, double y);
double div(double x, double y);
double calculate(double x, double y, operation_func f);

int main() {
    operation_func pf[] = {add, sub, mul, div};

    double x, y;
    while (true) {
        cout << "Enter two numbers (q to quit): ";
        if (!(cin >> x >> y)) break;
        for (int i = 0; i < 4; i++) {
            cout << calculate(x, y, pf[i]) << endl;
        }
    }

    return 0;
}

double add(double x, double y) {
    cout << x << "+" << y << "=";
    return x+y;
}

double sub(double x, double y) {
    cout << x << "-" << y << "=";
    return x-y;
}

double mul(double x, double y) {
    cout << x << "*" << y << "=";
    return x*y;
}

double div(double x, double y) {
    cout << x << "/" << y << "=";
    return x/y;
}

double calculate(double x, double y, operation_func f) {
    return f(x, y);
}
