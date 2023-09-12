#pragma once
#ifndef VECTOR2_H_
#define VECTOR2_H_
#include<iostream>

namespace VECTOR2 {
	class Vector2 {
	public:
		enum Mode { RECT, POL };
	private:
		double x;
		double y;
		Mode mode;

		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public:
		Vector2();
		Vector2(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector2();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return std::sqrt(x * x + y * y); }
		double angval()const {
			if (x == 0.0 && y == 0.0)
			{
				return(0.0);
			}
			else
				return(std::atan2(y, x));
		}
		void polar_mode();
		void rect_mode();
		Vector2 operator+(const Vector2& b)const;
		Vector2 operator-(const Vector2& b)const;
		Vector2 operator-()const;
		Vector2 operator*(double n)const;

		friend Vector2 operator*(double n, const Vector2& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
	};
}
#endif // !VECTOR_H_