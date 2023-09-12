#include <cstring>
#include <iostream>

void strcount(const std::string str);

int main() {

  std::string input;
  std::cout << "Enter a line:\n";
  getline(std::cin, input);
  while (std::cin) {
    strcount(input);
    std::cout << "Enter next line (empty line to quit):\n";
    getline(std::cin, input);
    if (input == "") {
      break;
    }
  }
  std::cout << "Bye.\n";
  system("pause");
  return 0;
}

void strcount(const std::string str) {
  int num = 0;
  static int total = 0;
  std::cout << str << " contains ";
  while (str[num++])
    ;

  total += num - 1;
  std::cout << num - 1 << " characters\n";
  std::cout << total << " characters total\n";
}