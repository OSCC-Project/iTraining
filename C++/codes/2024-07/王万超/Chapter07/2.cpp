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

struct box {
  /* data */
  char maker[40];
  float height;
  float width;
  float length;
  float volume;
};

void sset(box *b) {
     b->volume = b->height * b->length * b->width;
      }

box ssset(box b) {
  box bb;
  bb = b;
  bb.volume = bb.height * bb.length * bb.width;
  return bb;
}

void show(box a1) {
  cout << a1.height << ' ' << a1.length << ' ' << a1.width << ' ' << a1.volume
       << ' ' << a1.maker << endl;
}
int main(int argc, char const *argv[]) {
  /* code */
  box a1 = {"wangwanchao", 10, 20, 30};
  box a2 = {"chenshijiao", 1, 2, 3};
  box a;
  sset(&a1);
  show(a1);
  a=ssset(a2);
  show(a);
  show(a2);
  return 0;
}
