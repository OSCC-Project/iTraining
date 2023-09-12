#include <cstring>
#include <iostream>

struct CandyBar {
  char _name[20];
  double _weight;
  int _calories;
};

void set_CandyBar(CandyBar &C, const char *name = "Millennium Munch",
                  double weight = 2.85, int calories = 350);
void show_CandyBar(const CandyBar &C);

int main() {
  CandyBar candybar, C1;
  set_CandyBar(candybar);
  show_CandyBar(candybar);
  set_CandyBar(C1, "abc", 23.2, 120);
  show_CandyBar(C1);

  system("pause");
  return 0;
}

void set_CandyBar(CandyBar &C, const char *name, double weight, int calories) {
  strcpy(C._name, name);
  C._weight = weight;
  C._calories = calories;
}

void show_CandyBar(const CandyBar &C) {
  std::cout << "CandyBar's name is " << C._name << std::endl;
  std::cout << "CandyBar's weight is " << C._weight << std::endl;
  std::cout << "CandyBar's calories is " << C._calories << std::endl;
}