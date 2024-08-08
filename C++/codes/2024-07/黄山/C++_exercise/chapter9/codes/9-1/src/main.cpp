#include "golf.h"

int main(int argc, char** argv){
    while(true){
        golf g;
        if(setgolf(g)==0) break;
        showgolf(g);
        // handicap(g, 23);
        // showgolf(g);
    }
}