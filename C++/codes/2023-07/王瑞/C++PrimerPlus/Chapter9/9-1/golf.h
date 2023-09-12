#ifndef GOLF_H_
#define GOLF_H_

const int Len = 40;
struct golf {
  char fullname[Len];
  int handicap;
};

void setGolf(golf &g, const char *name, int hc);

int setGolf(golf &g);

void setHandicap(golf &g, int hc);

void showGolf(const golf &g);

#endif
