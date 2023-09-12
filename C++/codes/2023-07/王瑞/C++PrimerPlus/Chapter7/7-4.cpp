#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main() {
  double total_1, choices_1, total_2, choices_2;
  std::cout << "Enter the total number of choices on the game card and\n"
               "the number of picks allowed:\n";
  while ((std::cin >> total_1 >> choices_1 >> total_2 >> choices_2) &&
         choices_1 <= total_1 && choices_2 <= total_2) {
    std::cout << "You have one choice in ";
    std::cout << probability(total_1, choices_1) *
                     probability(total_2, choices_2);
    std::cout << " of winning.\n";
    std::cout << "Next four numbers (q to quit): ";
  }
  std::cout << "bye\n";
  return 0;
}

long double probability(unsigned numbers, unsigned picks) {
  long double result = 1.0;
  long double n;
  unsigned p;
  for (n = numbers, p = picks; p > 0; n--, p--) {
    result = result * n / p;
  }
  return result;
}