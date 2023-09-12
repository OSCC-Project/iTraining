#include "plorg.h"
#include <cstring>
#include <iostream>

int main() {
  Plorg text;
  text.showPlorg();
  text.changePlorg(10);
  text.showPlorg();
  Plorg text2("name");
  text2.showPlorg();
  system("pause");
  return 0;
}