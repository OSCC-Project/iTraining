#include <iostream>

using namespace std;


typedef double (*function)(double, double);

double add(double x, double y);
double subtract(double x, double y);
double calculate(double x, double y, function func);

int main() {
    function func[] = {add, subtract};
    double x, y;
    while (true) {
        cout << "Enter two numbers : ";
        if (!(cin >> x >> y)) break;
        for (int i = 0; i < 2; i++) {
            cout << calculate(x, y, func[i]) << endl;
        }
    }

    return 0;
}

double add(double x, double y) {
    cout << "Result of add: " ;
    return x+y;
}

double subtract(double x, double y) {
    cout << "Result of subtract: ";
    return x-y;
}


double calculate(double x, double y, function func) {
    return func(x, y);
}
