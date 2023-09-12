#include <iostream>
#include "golf.h"

const int MAX_LEN = 5;

int main() {
    golf v[MAX_LEN];
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);

    v[0] = ann;

    int i;
    for (i = 1; i < MAX_LEN && setgolf(v[i]); i++);

    for (int j = 0; j < i; j++) {
        std::cout << "original: ";
        showgolf(v[j]);
        handicap(v[j], j-1);
        std::cout << "change handicap: ";
        showgolf(v[j]);
    }

    return 0;
}
