#include"time.h"
#include<iostream>

Time::Time() {
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m) {
	hours = h;
	minutes = m;
}

void Time::AddMin(int m) {
	hours = hours + (minutes + m) / 60;
	minutes = (minutes + m) % 60;
}

void Time::AddHr(int h) {
	hours = hours + h;
}

void Time::Reset(int h, int m) {
	hours = h;
	minutes = m;
}

Time operator+(const Time& t1, const Time& t2) {
	Time temp;
	temp.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
	temp.minutes = (t1.minutes + t2.minutes) % 60;
	return temp;
}

Time operator-(const Time& t1, const Time& t2) {
	Time temp;
	int a1 = t1.minutes + t1.hours * 60;
	int a2 = t2.minutes + t2.hours * 60;
	temp.hours = (a1 - a2) / 60;
	temp.minutes = (a1 - a2) % 60;
	return temp;
}

Time operator*(const Time& t, double m) {
	Time temp;
	temp.minutes = int(m * t.minutes) % 60;
	temp.hours = (m * t.minutes) / 60 + t.hours * m;
	return temp;
}

Time operator*(double m, const Time& t) {
	Time temp;
	temp.minutes = int(m * t.minutes) % 60;
	temp.hours = (m * t.minutes) / 60 + t.hours * m;
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
	os << "hours:" << t.hours << ",minutes:" << t.minutes;
	return os;
}