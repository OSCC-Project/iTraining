#include <iostream>
int Fill_array(double arr[], int n);
void Show_array(const double arr[], int n);
void Reverse_array(double arr[], int n);
const int arsize = 10;
int main() {
  double arr[arsize];
  int n = Fill_array(arr, arsize);
  Show_array(arr, n);
  Reverse_array(arr, n);
  Show_array(arr, n);
  Reverse_array(arr, n);
  Reverse_array(arr + 1, n - 2);
  Show_array(arr, n);
  return 0;
}

int Fill_array(double arr[], int n) {
  int i = 0;
  std::cout << "You can enter up to " << arsize;
  std::cout << " numbers (q to terminate)." << std::endl;
  std::cout << "Number #1: ";
  while (i < n && std::cin >> arr[i]) {
    if (++i < arsize) {
      std::cout << "Number #" << i + 1 << ": ";
    }
  }
  return i;
}
void Show_array(const double arr[], int n) {
  std::cout << "All numbers:" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout.put('\n');
}

void Reverse_array(double arr[], int n) {
  for (int i = 0; i < n / 2; i++) {
    double temp = arr[n - 1 - i];
    arr[n - 1 - i] = arr[i];
    arr[i] = temp;
  }
}