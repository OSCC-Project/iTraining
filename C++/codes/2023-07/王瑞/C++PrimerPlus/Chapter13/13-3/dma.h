#ifndef DMA_H_
#define DMA_H_
#include <iostream>

class ABC {
public:
  ABC();
  ~ABC();
  virtual void viewInfo() = 0;
};

class baseDMA : public ABC {
public:
  baseDMA(const char *l = "null", int r = 0);
  baseDMA(const baseDMA &rs);
  virtual ~baseDMA();
  baseDMA &operator=(const baseDMA &rs);
  friend std::ostream &operator<<(std::ostream &os, const baseDMA &rs);
  virtual void viewInfo();

private:
  char *_label;
  int _rating;
};

class lacksDMA : public baseDMA {
public:
  lacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
  lacksDMA(const char *c, const baseDMA &rs);
  friend std::ostream &operator<<(std::ostream &os, const lacksDMA &ls);
  virtual void viewInfo();

private:
  enum { COL_LEN = 40 };
  char _color[COL_LEN];
};

class hasDMA : public baseDMA {
public:
  hasDMA(const char *s = "none", const char *l = "null", int r = 0);
  hasDMA(const char *s, const baseDMA &rs);
  hasDMA(const hasDMA &hs);
  ~hasDMA();
  hasDMA &operator=(const hasDMA &rs);
  friend std::ostream &operator<<(std::ostream &os, const hasDMA &rs);
  virtual void viewInfo();

private:
  char *_style;
};

#endif
