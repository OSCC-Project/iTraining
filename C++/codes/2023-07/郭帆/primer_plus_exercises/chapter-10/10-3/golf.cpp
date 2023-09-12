#include <iostream>
#include <string>
#include "golf.h"

Golf::Golf(const char * name, int hc) {
    strcpy(fullname, name);
    handicap = hc;
}

Golf::Golf() {
    char in_name[Len];
    int in_handicap;
    
    std::cout << "Enter a name: ";
    std::cin.getline(in_name, Len);
    
    std::cout << "Enter handicap: ";
    std::cin >> in_handicap;
    std::cin.get();
    
    *this = Golf(in_name, in_handicap);
}

void Golf::set_handicap(int hc) {
    handicap = hc;
}

void Golf::show() const {
    std::cout << "name: " << fullname << ", handicap: " << handicap << std::endl;
}
