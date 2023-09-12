#include "golf.h"
#include <iostream>

int main() {
  Golf text1;
  text1.showGolf();
  Golf text2("abc", 12);
  text2.showGolf();
  text2.setHandicap(10);
  text2.showGolf();
  system("pause");
  return 0;
}