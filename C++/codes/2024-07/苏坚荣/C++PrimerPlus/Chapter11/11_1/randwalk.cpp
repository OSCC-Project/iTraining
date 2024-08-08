// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>   // rand(), srand() prototypes
#include <ctime>     // time() prototype
#include "vector.h"
#include<fstream>

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));  // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;

	ofstream fout;
	fout.open("thewalk.txt");
	fout << "0: " << result << endl;

	double dstep;
	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		int cnt = 1;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			fout << cnt << ": " << result << endl;
			cnt++;
			steps++;
		}

		cout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		cout << result << endl;

		fout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		fout << result << endl;

		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return 0;
}
