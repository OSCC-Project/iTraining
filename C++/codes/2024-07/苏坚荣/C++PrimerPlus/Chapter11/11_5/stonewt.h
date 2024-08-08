// stonewt.h -- definition for the Stonewt class
#ifndef STONEWT_H
#define STONEWT_H

const int Lbs_per_stn = 14;

class Stonewt
{
public:
	enum Mode { STONE, INT_POUNDS, FLOAT_POUNDS };

private:
	//enum { Lbs_per_stn = 14 }; // pounds per stone
	int stone;               // whole stones
	double pds_left;         // fractional pounds
	double pounds;           // entire weight in pounds
	Mode mode;

public:
	Stonewt(double lbs, Mode form = FLOAT_POUNDS);     // constructor for double pounds
	Stonewt(int stn, double lbs, Mode form = STONE); // constructor for stone, lbs
	Stonewt();               // default constructor
	~Stonewt();
	void show_lbs() const;   // show weight in pounds format
	void show_stn() const;   // show weight in stone format
	void setMode(Mode form);
	friend Stonewt operator+(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator-(const Stonewt& s1, const Stonewt& s2);
	friend Stonewt operator*(const Stonewt& s1, int m);
	friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);

};

#endif
