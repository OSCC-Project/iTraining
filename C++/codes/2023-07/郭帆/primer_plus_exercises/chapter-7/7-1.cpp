#include <iostream>

using namespace std;

double calc_avg(int x, int y);

int main() {
    int x, y;
    while (true) {
        cout << "input two numbers: ";

        cin >> x >> y;
        if (x*y == 0) break;

        cout << "result: " << calc_avg(x, y) << endl;
    }

    return 0;
}

double calc_avg(int x, int y) {
    return 2.0 * x * y / (x+y);
}
