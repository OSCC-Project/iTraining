// stonewt.cpp -- Stonewt methods
#include <iostream>
using std::cout;
#include "stonewt.h"

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Mode form)
{
	stone = int(lbs) / Lbs_per_stn;   // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	mode = form;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Mode form)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	mode = form;
}

Stonewt::Stonewt()    // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	mode = FLOAT_POUNDS;
}

Stonewt::~Stonewt()   // destructor
{
}

//// show weight in stones
//void Stonewt::show_stn() const
//{
//	cout << stone << " stone, " << pds_left << " pounds\n";
//}
//
//// show weight in pounds
//void Stonewt::show_lbs() const
//{
//	cout << pounds << " pounds\n";
//}

void Stonewt::setMode(Mode form)
{
	mode = form;
}

Stonewt operator+(const Stonewt& s1, const Stonewt& s2)
{
	Stonewt result;
	result.pounds = s1.pounds + s2.pounds;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = int(result.pounds) % Lbs_per_stn + result.pounds - int(result.pounds);

	return result;
}

Stonewt operator-(const Stonewt& s1, const Stonewt& s2)
{
	Stonewt result;
	result.pounds = s1.pounds - s2.pounds;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = int(result.pounds) % Lbs_per_stn + result.pounds - int(result.pounds);
	return result;
}

Stonewt operator*(const Stonewt& s1, int m)
{
	Stonewt result;
	result.pounds = s1.pounds * m;
	result.stone = int(result.pounds) / Lbs_per_stn;
	result.pds_left = int(result.pounds) % Lbs_per_stn + result.pounds - int(result.pounds);
	return result;
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s)
{
	if (s.mode == Stonewt::STONE) {
		os << s.stone << " stone, " << s.pds_left << " pounds\n";
	}
	else if (s.mode == Stonewt::INT_POUNDS) {
		os << int(s.pounds) << " pounds\n";
	}
	else {
		os << s.pounds << " pounds\n";
	}
	return os;
}
