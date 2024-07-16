#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include "stock10.h"
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    cout << "Using constructors to create new objects\n";
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();
    cout<<"-------------------------------------"<<endl;
    Stock stock2 = Stock("Boffo Objects", 2, 2.0);
    stock2.show();
    cout<<"-------------------------------------"<<endl;

    stock2 = stock1;
    stock2.show();
    cout<<"-------------------------------------"<<endl;
    stock1.show();
    cout<<"-------------------------------------"<<endl;
    cout<<"Done!\n"<<endl;  

    return 0;
}
