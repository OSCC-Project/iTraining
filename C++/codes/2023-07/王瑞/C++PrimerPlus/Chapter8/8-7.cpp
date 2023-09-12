#include <iostream>

template <typename T> void SumArray(T arr[], int n);
template <typename T> void SumArray(T *arr[], int n);
struct debts {
  char name[50];
  double amount;
};

int main() {
  int things[6] = {13, 31, 103, 301, 310, 130};
  struct debts mr_E[3] = {
      {"Ima Wolfe", 2400.0}, {"Ura Foxe", 1300.0}, {"Iby Stout", 1800.0}};
  double *pd[3];
  for (int i = 0; i < 3; i++) {
    pd[i] = &mr_E[i].amount;
  }
  std::cout << "Listing Mr. E's total of things:\n";
  SumArray(things, 6);
  std::cout << "Listing Mr. E's total of debts:\n";
  SumArray(pd, 3);
  system("pause");
  return 0;
}

template <typename T> void SumArray(T arr[], int n) {
  T sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  std::cout << sum << std::endl;
}

template <typename T> void SumArray(T *arr[], int n) {
  T sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *arr[i];
  }
  std::cout << sum << std::endl;
}
