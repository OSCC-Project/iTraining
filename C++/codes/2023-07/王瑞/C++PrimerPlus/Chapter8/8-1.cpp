#include <iostream>

void print_string(const char *str, int n = 0);

int main() {
  const char *str = "This is a test.";

  std::cout << "Only one parameter, print 1 times:" << std::endl;
  print_string(str);
  std::cout << "Having two parameter can print 1 times:" << std::endl;
  print_string(str, 3);
  std::cout << "Bye." << std::endl;
  system("pause");
  return 0;
}

void print_string(const char *str, int n) {
  static int flag = 0;
  flag++;
  if (n == 0) {
    std::cout << str << std::endl;
  } else {
    for (int i = 0; i < flag; i++) {
      std::cout << str << std::endl;
    }
  }
  std::cout << std::endl;
}
