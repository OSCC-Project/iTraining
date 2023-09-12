#include <iostream>
#include "golf.h"

const int MAX_LEN = 5;

int main() {
    Golf v[MAX_LEN];
    Golf ann("Ann Birdfree", 24);

    v[0] = ann;

    for (int j = 0; j < MAX_LEN; j++) {
        std::cout << "original: ";
        v[j].show();
        v[j].set_handicap(j-1);
        
        std::cout << "change handicap: ";
        v[j].show();
    }

    return 0;
}
