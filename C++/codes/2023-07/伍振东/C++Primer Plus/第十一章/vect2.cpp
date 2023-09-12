#include<iostream>
#include"vect2.h"

namespace VECTOR2 {
	const double Rad_to_deg = 45.0 / std::atan(1.0);

	void Vector2::set_x() {
		x = magval() * std::cos(angval());
	}

	//void Vector2::set_y() {
	//	y = magval() * std::sin(ang);
	//}

	//void Vector2::set_mag() {
	//	mag = std::sqrt(x * x + y * y);
	//}

	//void Vector2::set_ang() {
	//	if (x == 0.0 && y == 0.0)
	//	{
	//		ang = 0.0;
	//	}
	//	else
	//		ang = std::atan2(y, x);
	//}
	Vector2::Vector2() {
		x = y = 0.0;
		mode = RECT;
	}

	Vector2::Vector2(double n1, double n2, Mode form) {
		x = n1;
		y = n2;
	}

	void Vector2::reset(double n1, double n2, Mode form) {
		mode = form;
		x = n1;
		y = n2;
		
	}

	Vector2::~Vector2()
		// destructor
	{

	}
	void Vector2::polar_mode()
		// set to polar mode
	{
		mode = POL;
	}
	Vector2 Vector2::operator+(const Vector2& b) const {
		return Vector2(x + b.x, y + b.y);
	}
	Vector2 Vector2::operator-(const Vector2& b) const {
		return Vector2(x - b.x, y - b.y);
	}
	Vector2 Vector2::operator-()const {
		return Vector2(-x, -y);
	}
	Vector2 Vector2::operator*(double n)const {
		return Vector2(n * x, n * y);
	}
	Vector2 operator*(double n, const Vector2& a) {
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector2& v)
	{
		if (v.mode == Vector2::RECT) {
			os << "(x,y) = (" << v.x << "," << v.y << ")";
		}
		else {
			os << "(m,a) = (" << v.magval() << "," << v.angval() * Rad_to_deg << ")";
		}
		return os;
	}
}