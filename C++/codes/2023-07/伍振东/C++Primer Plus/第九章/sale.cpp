#include"sale.h"
#include<iostream>

void SALES::setSales(Sales& s, const double ar[], int n) {
	s.max = ar[0];
	s.min = ar[0];
	double sum = 0;
	for (int i = 0; i < n && i < 4; ++i) {
		s.sales[i] = ar[i];
		s.max = s.max >= ar[i] ? s.max : ar[i];
		s.min = s.min <= ar[i] ? s.min : ar[i];
		sum += ar[i];
	}
	s.average = sum / n;
	if (n < 4) {
		for (int i = n; i < 4; ++i) {
			s.sales[i] = 0;
		}
	}
}

// 输入四个元素来初始化
void SALES::setSales(Sales& s) {
	using namespace std;
	cout << "输入四个数字：";
	for (int i = 0; i < 4; ++i) {
		cin >> s.sales[i];
	}
	s.max = s.sales[0];
	s.min = s.sales[0];
	s.average = 0;
	for (int i = 0; i < 4; ++i) {
		s.max = s.max >= s.sales[i] ? s.max : s.sales[i];
		s.min = s.min <= s.sales[i] ? s.min : s.sales[i];
		s.average += s.sales[i];
	}
	s.average /= 4;
}

void SALES::showSales(const Sales& s) {
	using namespace std;
	cout << "四个元素分别为：";
	for (int i = 0; i < 4; ++i) {
		cout << s.sales[i] << ' ';
	}
	cout << endl;
	cout << "最大值为：" << s.max << endl;
	cout << "最小值为：" << s.min << endl;
	cout << "平均值为：" << s.average << endl;
}