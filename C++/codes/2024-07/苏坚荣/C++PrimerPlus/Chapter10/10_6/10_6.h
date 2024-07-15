#pragma once

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showMove() const;
	Move add(const Move& m) const;
	void resetMove(double a = 0, double b = 0);
};