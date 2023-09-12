#include <iostream>

using namespace std;

long long factorial(unsigned n);

int main() {
    int n;

    while (true) {
        cout << "Enter a number: ";

        if (!(cin >> n) || n < 0) break;

        cout << "result: " << factorial(n) << endl;
    }

    return 0;
}

long long factorial(unsigned n) {
    if (n == 0) return 1;
    return n * factorial(n-1);
}
