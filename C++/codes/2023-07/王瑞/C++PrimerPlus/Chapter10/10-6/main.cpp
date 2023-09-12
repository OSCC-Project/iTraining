#include "move.h"
#include <iostream>

using namespace std;

int main() {
  Move text;
  text.showMove();
  text.resetMove(10, 23);
  text.showMove();
  Move text2(1, 2);
  text = text.addMove(text2);
  text.showMove();
  system("pause");
  return 0;
}