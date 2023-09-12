#include <iostream>

using namespace std;

long double probablilty(unsigned number, unsigned picks);

int main() {
    double field_total_number, choices, range_total_number;
    cout << "Enter the total number of field choices on the game card and\n"
            "the number of picks allowd and\n"
            "the total number of range choices on the game card: " << endl;
    while ((cin >> field_total_number >> choices >> range_total_number) && choices <= field_total_number) {
        cout << "you have one chance in ";
        cout << probablilty(field_total_number, choices) * probablilty(range_total_number, 1);
        cout << " of winning.\n";
        cout << "Next two numbers (q to quit): ";
    }
    cout << "bye" << endl;

    return 0;
}

long double probablilty(unsigned number, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = number, p = picks; p > 0; n--, p--) {
        result = result * n / p;
    }

    return result;
}
