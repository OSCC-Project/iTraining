#ifndef PLORG_H_
#define PLORG_H_

class Plorg {
public:
  Plorg();
  Plorg(const char *name_);
  ~Plorg();
  void changePlorg(const int c);
  void showPlorg() const;

private:
  static const int MAX = 19;
  char _name[MAX];
  int _CI;
};
#endif