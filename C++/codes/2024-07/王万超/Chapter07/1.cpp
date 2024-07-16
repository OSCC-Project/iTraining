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


int Tsum(int x,int y)
{
    return 2.0*x*y/(x+y);
}

int main() {
  int x, y;
  int resule;
  while (cin >> x >> y) {
    if (x == 0 || y == 0) break;
    resule=Tsum(x,y);
    cout<<resule<<endl;
  }

  return 0;
}
