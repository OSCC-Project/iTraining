#include<iostream>

#include"move.h"

int main(int argc, char** argv){
    Move m1(3, 4);
    Move m2(5, 6);
    m1.showmove();
    m2.showmove();
    Move m3 = m1.add(m2);
    m3.showmove();
    m3.reset();
    m3.showmove();
    return 0;
}