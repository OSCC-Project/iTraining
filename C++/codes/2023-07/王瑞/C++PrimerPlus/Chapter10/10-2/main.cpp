#include "person.h"
#include <cstring>
#include <iostream>

int main() {
  Person one;
  Person two("Smythcraft");
  Person three("Dimwiddy", "Sam");
  one.showPerson();
  one.formalShowPerson();

  two.showPerson();
  two.formalShowPerson();

  three.showPerson();
  three.formalShowPerson();
  system("pause");
  return 0;
}