#include <iostream>

using namespace std;

long int  factorial(unsigned n);

int main() {
    int n = 0;
    while (true) {
        cout << "Please enter a integer number: ";
        if (!(cin >> n) || n < 0) break;
        cout << "factorial: " << factorial(n) << endl;
    }

    return 0;
}

long int factorial(unsigned n) {
    if (n > 0) 
        return n * factorial(n-1);
    else {
        return 1;
    }
}

 
