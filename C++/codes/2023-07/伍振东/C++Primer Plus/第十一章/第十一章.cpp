#include<ctime>
#include<fstream>
#include<istream>
#include"vect.h"	// 10.1
#include"vect2.h"	// 10.2
#include"time.h"	// 10.4
#include"complex.h"
using namespace std;

// 第十一章
// 11.1：修改程序清单11.15
void controller10_1() {
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit):";
	ofstream fout;
	fout.open("walkrand.txt");
	while (cin >> target) {
		cout << "Enter step length:";
		if (!(cin >> dstep)) {
			break;
		}
		fout << "Target Distance:" << target << ", Step Size:" << dstep << "\n";
		int i = 0;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			cout << i << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
			fout << i << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
			i++;

		}
		cout << "After" << steps << "steps, the subject have the following location:\n";
		fout << "After" << steps << "steps, the subject have the following location:\n";
		cout << result << endl;
		fout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		fout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		fout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
	fout.close();
}

// 10.2：修改程序头文件后测试
void controller10_2() {
	using VECTOR2::Vector2;
	srand(time(0));
	double direction;
	Vector2 step;
	Vector2 result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "Enter target distance (q to quit):";
	while (cin >> target) {
		cout << "Enter step length:";
		if (!(cin >> dstep)) {
			break;
		}
		int i = 0;
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector2::POL);
			result = result + step;
			steps++;
			cout << i << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
			i++;

		}
		cout << "After" << steps << "steps, the subject have the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
}

// 10.3：报告最高，最低和平均步数
void controller10_3() {
	int max_step = 0;
	int min_step = 65535;
	int sum = 0;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	int steps = 0;
	double target;
	double dstep;
	int i = 0;
	cout << "Enter target distance (q to quit):";
	while (cin >> target) {
		cout << "Enter step length:";
		if (!(cin >> dstep)) {
			break;
		}
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;

		}
		i++;
		max_step = max(max_step, steps);
		min_step = min(min_step, steps);
		sum += steps;
		cout << "max_step:" << max_step << " min_steps:" << min_step << " average_steps:" << double(sum)/i << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit):";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')continue;
}

// 10.4：time.h和time.cpp
void controller10_4() {

	Time t1(13, 15);
	Time t2(2, 18);
	Time temp;

	cout << "t1 and t2:\n";
	cout << t1 << "; " << t2 << endl;
	temp = t1 + t2;
	cout << "t1 + t2: " << temp << endl;
	temp = t1 * 1.17;
	cout << "t1 * 1.9: " << temp << endl;
	cout << "4.0 * t2: " << 10.0 * t2 << endl;
}

// 10.5-6：运算符重载，+、-、*、<<运算，大同小异，略

// 10.7：复数的运算重载
void controller10_7() {
	complex a(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c) {
		cout << "c is" << c << "\n";
		cout << "complex conjugate is" << ~c << "\n";
		cout << "a is" << a << endl;
		cout << "a + c is" << a + c << endl;
		cout << "a - c is" << a - c << endl;
		cout << "a * c is" << a * c << endl;
		cout << "2 * c is" << 2 * c << endl;
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
}


int main() {
	//controller10_1();
	//controller10_2();
	//controller10_3();
	//controller10_4();
	controller10_7();
	system("PAUSE");
	return 0;
}