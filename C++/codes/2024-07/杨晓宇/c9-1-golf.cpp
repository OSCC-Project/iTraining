#include "c9-1-golf.h"

void setgolf(golf &g, const char *name, int hc)
{
    int a = 0;
    while(name[a] != '\0')
    {
        g.fullname[a] = name[a];
        ++a;
        if(a == Len)
        {
            --a;
            break;
        }
    }
    g.fullname[a] = name[a];
    g.handicap = hc;
    return;
}
int setgolf(golf &g)
{
    int temp = 1;
    cout << "Please input name character < 40 or n to skip" << endl;
    cin >> g.fullname;
    if(g.fullname[0] == 'n' && g.fullname[1] == '\0')
        temp = 0;
    cout << "Please input hc" << endl;
    cin >> g.handicap;
    return temp;
}
void handicap(golf &g, int hc)
{
    g.handicap = hc;
    return;
}
void showgolf(const golf &g)
{
    cout << g.fullname << endl << g.handicap << endl;
    return;
}