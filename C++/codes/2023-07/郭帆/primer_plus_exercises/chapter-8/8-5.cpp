#include <iostream>

using namespace std;


template <typename T>
T max5(T arr[5]);

int main() {
    int a[] = {1, 2, 3, 4, 5};
    double b[] = {2, 3, 4, 5, 6};

    cout << max5(a) << endl;
    cout << max5(b) << endl;

    return 0;
}

template <typename T>
T max5(T arr[5]) {
    T max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
