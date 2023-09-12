#include <cstring>
#include <iostream>

struct stringy {
  char *str;
  int cnt;
};

void set(stringy &Str, const char *s);
void const show(const stringy &Str, const int n = 1);
void const show(const std::string, const int n = 1);

int main() {
  stringy beany;
  char testing[] = "Reality isn't what it used to be.";
  set(beany, testing);
  show(beany);
  show(beany, 2);
  testing[0] = 'D';
  testing[1] = 'u';
  show(testing);
  show(testing, 3);
  show("Done!");
  system("pause");
  return 0;
}

void set(stringy &Str, const char *s) {
  Str.cnt = strlen(s);
  Str.str = new char[Str.cnt + 1];
  strcpy(Str.str, s);
}

void const show(const stringy &Str, const int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    std::cout << Str.str << std::endl;
  }
}

void const show(const std::string S, const int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    std::cout << S << std::endl;
  }
}
