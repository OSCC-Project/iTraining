#include <iostream>

int initialize_array(double arr[], int n);
void show_array(double arr[], int n);
double count_average(double arr[], int n);

const int arr_size = 10;
int main() {
  double grades[arr_size];
  int n = initialize_array(grades, arr_size);
  show_array(grades, n);
  std::cout << "Average golf scores: " << count_average(grades, n) << std::endl;
  return 0;
}

int initialize_array(double arr[], int n) {
  int i = 0;
  std::cout << "You can enter up to " << arr_size;
  std::cout << " grades (q to terminate)." << std::endl;
  std::cout << "Golf scores #1: ";
  while (i < n && std::cin >> arr[i]) {
    if (++i < arr_size) {
      std::cout << "Golf scores #" << i + 1 << ": ";
    }
  }
  return i;
}
void show_array(double arr[], int n) {
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}
double count_average(double arr[], int n) {
  double total = 0.0;
  for (int i = 0; i < n; i++) {
    total += arr[i];
  }
  return total / n;
}
