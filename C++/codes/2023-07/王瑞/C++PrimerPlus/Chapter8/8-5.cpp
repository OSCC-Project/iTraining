#include <iostream>

template <typename T> T max5(T *arr, int arr_size);

int main() {
  const int arr_size = 5;
  int int_arr[arr_size] = {5, 6, 4, 9, 7};
  double dou_arr[arr_size] = {5.2, 6.3, 1.5, 9.5, 4.3};
  std::cout << " the max int_arr: " << max5(int_arr, arr_size) << std::endl;
  std::cout << " the max dou_arr: " << max5(dou_arr, arr_size) << std::endl;
  system("pause");
  return 0;
}

template <typename T> T max5(T *arr, int arr_size) {
  T max = arr[0];
  for (int i = 1; i < arr_size; ++i) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}