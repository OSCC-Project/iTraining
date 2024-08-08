#include <iostream>

using namespace std;

template <typename  T> 
T max5 (T arr[5]);

int main() {
    int intArray[5] = {4, 6, 1, 7, 2};
    double doubleArray[5] = {2.1, 1.2, 5.7, 3.8, 4.1};
    
    int maxInt = max5(intArray);
    cout << "Max element in intArray: " << maxInt << endl;
    double maxDouble = max5(doubleArray);
    cout << "Max element in doubleArray: " << maxDouble << endl;

    return 0;
}

template <typename  T> 
T max5(T arr[5]) {
    T max = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}