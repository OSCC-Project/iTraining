#include "Move.hpp"

int main() {
   
    Move move1(3, 4);
    move1.showmove(); 

    
    Move move2(2, 6);
    move2.showmove(); 

    
    Move move3 = move1.add(move2);
    move3.showmove(); 

    
    move1.reset(0, 0);
    move1.showmove(); 

    return 0;
}
