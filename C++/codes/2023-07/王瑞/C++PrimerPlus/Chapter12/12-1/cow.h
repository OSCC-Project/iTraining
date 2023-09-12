#ifndef COW_H_
#define COW_H_

class Cow {
public:
  Cow();
  Cow(const char *nm, const char *ho, double wt);
  Cow(const Cow &c);
  ~Cow();
  Cow &operator=(const Cow &c);
  void showCow() const;

private:
  char _name[20];
  char *_hobby;
  double _weight;
};

#endif