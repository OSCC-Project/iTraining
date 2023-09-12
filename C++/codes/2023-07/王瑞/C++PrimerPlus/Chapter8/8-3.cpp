#include <cctype>
#include <iostream>
#include <string>

std::string change(std::string &str);

int main() {
  std::cout << "Enter a string (q to quit): " << std::endl;
  std::string str;
  getline(std::cin, str);
  while (str != "q") {
    str = change(str);
    std::cout << str << std::endl;
    std::cout << "Enter the next string (q to quit):";
    getline(std::cin, str);
  }
  system("pause");
  return 0;
}

std::string change(std::string &str) {
  for (int i = 0; str[i]; i++) {
    str[i] = toupper(str[i]);
  }
  return str;
}