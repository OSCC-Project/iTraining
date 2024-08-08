#include <iostream>

using namespace std;
const int max_length = 20;
int Fill_array(double arr[], int length);
void Show_array(const double arr[], int length);
void Reverse_array(double arr[], int length);

int main() {
    double arr[max_length] = {};
    int length = max_length;
    length = Fill_array(arr, length);
    Show_array(arr, length);
    Reverse_array(arr, length);
    Show_array(arr, length);
    Reverse_array(arr+1, length-2);
    Show_array(arr, length);

    return 0;
}

int Fill_array(double arr[], int length) {
    double temp;
    int i;
    for (i = 0; i < length; i++) {
        cout << "Enter a double type value (other to quit): ";
        if (!(cin >> temp)) break;
        arr[i] = temp;
    }
    return i;
}

void Show_array(const double arr[], int length) {
    cout << "array: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Reverse_array(double arr[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        double temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}