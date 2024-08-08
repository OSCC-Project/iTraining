#include <iostream>
#include "golf.h"
#include <string.h>
using namespace std;

int setgolf(golf &g)
{
    cout << "Enter the name of the player: ";
    cin.getline(g.fullname, Len);
    if(g.fullname[0] == '\0')
        return 0;
    cout<<"Enter the handicap of the player: "<<g.fullname<<": "<<endl;
    while (!(cin >> g.handicap))
    {
        cin.clear();
        while (cin.get() != '\n')
            continue;
        cout << "Please enter a number: ";
    }
    cin.get();
    return 1;
}

void setgolf(golf &g, const char *name, int hc)
{
    strncpy_s(g.fullname, name, Len);
    g.handicap = hc;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}


void showgolf(const golf &g)
{
    cout << "Name: " << g.fullname << endl;
    cout << "Handicap: " << g.handicap << endl;
}