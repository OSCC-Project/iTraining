#ifndef CD_H_
#define CD_H_

class Cd {
public:
  Cd(char *s1, char *s2, int n, double x);
  Cd(const Cd &d);
  Cd();
  virtual ~Cd();
  virtual void reportInfo() const;
  virtual Cd &operator=(const Cd &d);

private:
  char _performers[50];
  char _label[20];
  int _selections;
  double _playtime;
};

class Classic : public Cd {
public:
  Classic(char *s0, char *s1, char *s2, int n, double x);
  Classic(char *s0, Cd &rs);
  Classic();
  virtual ~Classic();
  virtual void reportInfo() const;
  virtual Classic &operator=(const Classic &d);

private:
  char _mainworks[50];
};

#endif
