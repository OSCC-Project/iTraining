#include <iostream>

const int SLEN = 30;
struct student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main() {
  std::cout << "Enter class size: ";
  int class_size;
  std::cin >> class_size;
  while (std::cin.get() != '\n')
    continue;

  student *ptr_stu = new student[class_size];
  int entered = getinfo(ptr_stu, class_size);
  for (int i = 0; i < entered; i++) {
    display1(ptr_stu[i]);
    display2(&ptr_stu[i]);
  }
  display3(ptr_stu, entered);
  delete[] ptr_stu;
  std::cout << "Done\n";
  return 0;
}

int getinfo(student pa[], int n) {
  int i = 0;
  std::cout << "You can enter up to " << n;
  std::cout << " students' messages (enter to terminate)." << std::endl;
  for (; i < n; i++) {
    std::cout << "Enter value #" << (i + 1) << ": " << std::endl;
    std::cout << "Enter the fullname(a blank line to quit): ";
    std::cin.getline(pa[i].fullname, SLEN);
    if ('\0' == pa[i].fullname[0]) {
      break;
    }
    std::cout << "Enter the hobby: ";
    std::cin.getline(pa[i].hobby, SLEN);
    std::cout << "Enter the ooplevel: ";
    while (!(std::cin >> pa[i].ooplevel)) {
      std::cin.clear();
      while (std::cin.get() != '\n')
        continue;
      std::cout << "Please enter an number: ";
    }
    std::cin.get();
  }
  return i;
}

void display1(student st) {
  std::cout << "\nname: " << st.fullname << std::endl;
  std::cout << "hobby: " << st.hobby << std::endl;
  std::cout << "ooplevel" << st.ooplevel << std::endl;
}
void display2(const student *ps) {
  std::cout << "\nname: " << ps->fullname << std::endl;
  std::cout << "hobby: " << ps->hobby << std::endl;
  std::cout << "ooplevel" << ps->ooplevel << std::endl;
}
void display3(const student pa[], int n) {
  int i;
  std::cout << "There are " << n << " students' informations: " << std::endl;
  for (i = 0; i < n; i++) {
    std::cout << "Stduent #" << (i + 1) << ": " << std::endl;
    std::cout << "name: " << pa[i].fullname << std::endl;
    std::cout << "hobby: " << pa[i].hobby << std::endl;
    std::cout << "ooplevel: " << pa[i].ooplevel << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
  }
}