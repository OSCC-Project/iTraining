// randwalk.cpp -- using the Vector class
// compile with the vect.cpp file
#include <iostream>
#include <cstdlib>   // rand(), srand() prototypes
#include <ctime>     // time() prototype
#include "vector.h"


int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));  // seed random-number generator
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	unsigned long maxsteps = 0;
	unsigned long minsteps = 4294967295;
	unsigned long totalsteps = 0;
	double averagesteps = 0.0;
	double target;

	int n, cnt;
	cout << "请输入测试的次数：";
	cin >> n;
	cnt = n;
	double dstep;
	cout << "Enter target distance: ";
	cin >> target;
	cout << "Enter step length: ";
	cin >> dstep;

	while (n--)
	{
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}

		/*cout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		cout << result << endl;

		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;*/

		if (steps > maxsteps) {
			maxsteps = steps;
		}
		if (steps < minsteps) {
			minsteps = steps;
		}
		totalsteps += steps;

		steps = 0;
		result.reset(0.0, 0.0);
	}
	averagesteps = totalsteps / cnt;
	cout << "最高步数：" << maxsteps << endl;
	cout << "最低步数：" << minsteps << endl;
	cout << "平均步数：" << averagesteps << endl;
	return 0;
}
