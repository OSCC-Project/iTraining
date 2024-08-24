#include<iostream>
#include"vintageport.h"

void show(const Port& pt){
    pt.show();
}

int main(int argc, char** argv){
    Port p1("Gallo", "tawny", 20);
    VintagePort p2("Gallo", 21, "Old Velvet", 1986);
    show(p1);
    show(p2);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;

    return 0;
}

