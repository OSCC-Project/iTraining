#include <iostream>
#include <string>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc) {
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g) {
    std::cout << "Enter a name: ";
    std::cin.getline(g.fullname, Len);
    
    if (strlen(g.fullname) == 0) return 0;
    
    std::cout << "Enter handicap: ";
    std::cin >> g.handicap;
    std::cin.get();
    
    return 1;
}

void handicap(golf & g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf & g) {
    std::cout << "name: " << g.fullname << ", handicap: " << g.handicap << std::endl;
}
