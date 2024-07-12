#include <iostream>
using namespace std;

double Calculate(double x, double y) {
	return 2.0 * x * y / (x + y);
}

int main()
{
	double a, b;

	while (1) {
		cout << "请输入两个数：" << endl;
		cin >> a >> b;
		if (a == 0 || b == 0)
			break;
		cout << "这两个数的调和平均数为：" << Calculate(a, b) << endl;
	}

	return 0;
}
