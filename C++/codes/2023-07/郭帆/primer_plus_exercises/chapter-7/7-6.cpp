#include <iostream>

using namespace std;

const int MAX_LEN = 10;

int Fill_array(double a[], int size);
void Show_array(const double a[], int size);
void Reverse_array(double a[], int size);

int main() {
    double a[MAX_LEN] = {};
    int size = MAX_LEN;

    size = Fill_array(a, size);
    Show_array(a, size);
    Reverse_array(a, size);
    Show_array(a, size);
    Reverse_array(&a[1], size-2);
    Show_array(a, size);

    return 0;
}

int Fill_array(double a[], int size) {
    int i;
    double x;
    for (i = 0; i < size; i++) {
        cout << "input a double value (s to stop): ";
        if (!(cin >> x)) break;
        a[i] = x;
    }
    return i;
}

void Show_array(const double a[], int size) {
    cout << "array: ";
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Reverse_array(double a[], int size) {
    int i = 0, j = size-1;
    while (i < j) {
        double temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}
