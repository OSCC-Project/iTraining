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
using namespace std;

struct CandyBar {
    string brand;
    double weight;
    int calories;
};
void sets(CandyBar &cd, string brand, double weight, int calories)
{
    cd.brand = brand;
    cd.weight = weight;
    cd.calories = calories;
}
void print(const CandyBar &candy)
{
    cout << candy.brand << " " << candy.weight << " " << candy.calories << endl;
}
int main(int argc, char const *argv[]) {
    /* code */
    CandyBar candy;
    sets(candy, "Mars", 2.3, 230);
    print(candy);
    return 0;
}
