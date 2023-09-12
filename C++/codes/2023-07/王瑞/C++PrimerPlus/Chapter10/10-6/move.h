#ifndef MOVE_H_
#define MOVE_H_

class Move {
public:
  Move(double a = 0, double b = 0);
  void showMove() const;
  Move &addMove(const Move &m) const;
  void resetMove(double a = 0, double b = 0);

private:
  double _x;
  double _y;
};
#endif