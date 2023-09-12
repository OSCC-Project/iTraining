#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR {
class Vector {
public:
  enum Mode { RECT, POL };
  Vector();
  Vector(double n1, double n2, Mode form = RECT);
  void resetVector(double n1, double n2, Mode form = RECT);
  ~Vector();
  double getXVal() const { return _x; }
  double getYVal() const { return _y; }
  double getMagVal() const { return _mag; }
  double getAngVal() const { return _ang; }
  void setPolarMode();
  void rectMode();
  Vector operator+(const Vector &b) const;
  Vector operator-(const Vector &b) const;
  Vector operator-() const;
  Vector operator*(double n) const;
  friend Vector operator*(double n, const Vector &a);
  friend std::ostream &operator<<(std::ostream &os, const Vector &v);

private:
  double _x;
  double _y;
  double _mag;
  double _ang;
  Mode mode;
  void setMag();
  void setAng();
  void setX();
  void setY();
};
} // namespace VECTOR

#endif
