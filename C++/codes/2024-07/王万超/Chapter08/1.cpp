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

void show(string *p,int n=0)
{
  for(int i=0;i<n;i++)
    cout<<*p<<endl;
}
int main(int argc, char const *argv[]) {
    /* code */
    string p="Hello World!";
    int num;
    cout<<"Enter a  number:"<<endl;
    cin>>num;
    show(&p,num);
   
    return 0;
}
