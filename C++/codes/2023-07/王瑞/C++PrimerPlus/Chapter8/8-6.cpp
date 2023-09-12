#include <cstring>
#include <iostream>

template <typename T> T maxn(T *arr, int n);
template <> char *maxn(char *str[], int n);

int main() {
  int int_arr[6] = {5, 7, 9, 1, 3, 6};
  double dou_arr[4] = {10.2, 20.9, 11.3, 15.3};
  std::string str[5] = {"a", "abc", "abcdef", "abcd", "abcdefj"};
  std::cout << "the int array max: " << maxn(int_arr, 6) << std::endl;
  std::cout << "the double array max: " << maxn(dou_arr, 4) << std::endl;
  std::cout << "the most long string: " << maxn(str, 5) << std::endl;
  system("pause");
  return 0;
}

template <typename T> T maxn(T *arr, int n) {
  T max = arr[0];
  int i = 1;
  for (; i < n; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  return max;
}

template <> char *maxn(char *str[], int n) {
  int i, j = 0;
  int max_num = strlen(str[0]);
  for (i = 0; i < n; i++) {
    if (max_num < strlen(str[i])) {
      j = i;
    }
  }
  char *max_str = str[j];
  return max_str;
}