#include <iostream>
#include "10_4.h"

namespace SALES
{
	Sales::Sales()
	{
		using namespace std;
		double max, min, total;
		cout << "请分别输入四个季度的销售额：";
		for (int i = 0; i < 4; i++) {
			cin >> _sales[i];
		}
		max = min = total = _sales[0];
		for (int i = 1; i < 4; i++) {
			if (_sales[i] > max) {
				max = _sales[i];
			}
			if (_sales[i] < min) {
				min = _sales[i];
			}
			total += _sales[i];
		}
		_average = total / 4;
		_max = max;
		_min = min;
	}

	Sales::Sales(const double ar[], int n)
	{
		int i = 0;
		double max = 0, min = ar[0], avg = 0, total = 0;
		for (i = 0; i < n; i++) {
			_sales[i] = ar[i];
			if (ar[i] > max) {
				max = ar[i];
			}
			if (ar[i] < min) {
				min = ar[i];
			}
			total += ar[i];
		}
		_average = total / n;
		_max = max;
		_min = min;
		if (i < 4) {
			for (int j = i; j < 4; j++) {
				_sales[j] = 0;
			}
		}
	}

	Sales::~Sales()
	{
	}


	void Sales::showSales() const
	{
		using namespace std;
		cout << "四个季度的销售额分别为：";
		for (int i = 0; i < 4; i++) {
			cout << _sales[i] << " ";
		}
		cout << endl;
		cout << "最大值：" << _max << endl;
		cout << "最小值：" << _min << endl;
		cout << "平均值：" << _average << endl;
	}

}

