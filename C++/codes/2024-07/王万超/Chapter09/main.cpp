#include  <iostream>
#include "golf.h"

int main()
{
    using namespace std;
    golf golfer[5];
    int i ;
    for(i = 0;i<1;i++)
    {
        if(setgolf(golfer[i]) == 0)
            break;
    }
    for(int j = 0;j<i;j++)
    {
        showgolf(golfer[j]);
    }
    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);
    handicap(ann, 30);
    showgolf(ann);

    return 0;
}