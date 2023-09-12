#include "bank.h"
#include <iostream>
#include <string>

int main() {
  Bank text1;
  text1.showBank();
  Bank text2("abc", "ef", 12.2);
  text2.showBank();
  text2.inputMoney(2.5);
  text2.outputMoney(3.3);
  text2.showBank();
  system("pause");
  return 0;
}