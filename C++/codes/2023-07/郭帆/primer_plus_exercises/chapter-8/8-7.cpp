#include <iostream>

using namespace std;

template <typename T>
T SumArray(T arr[], int n);

template <typename T>
T SumArray(T * arr[], int n);

struct debts {
    char name[50];
    double amount;
};

int main() {
    int thing[6] = { 13, 31, 103, 301, 310, 130 };
    int int_sum = 0;
    struct debts mr_E[3] = 
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double *pd[3];
    double double_sum = 0.0;
 
    for (size_t i = 0; i < 3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
 
    int_sum = SumArray(thing, 6);
    double_sum = SumArray(pd, 3);
 
    cout << "Sum of int array: " << int_sum << endl;
    cout << "Sum of double* array: " << double_sum << endl;
 
    return 0;
}

template <typename T>
T SumArray(T arr[], int n)
{
    T sum = arr[0];
 
    for (int i = 1; i < n; i++)
    {
        sum += arr[i];
    }
 
    return sum;
}
 
template <typename T>
T SumArray(T * arr[], int n)
{
    T sum = *(arr[0]);
    for (int i = 1; i < n; i++)
    {
        sum += *(arr[i]);
    }
 
    return sum;
}
