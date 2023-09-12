#include"sale.h"
#include<iostream>

Sales::Sales(const double ar[], int n) {
	
	max = ar[0];
	min = ar[0];
	double sum = 0;
	for (int i = 0; i < n && i < 4; ++i) {
		sales[i] = ar[i];
		max = max >= ar[i] ? max : ar[i];
		min = min <= ar[i] ? min : ar[i];
		sum += ar[i];
	}
	average = sum / n;
	if (n < 4) {
		for (int i = n; i < 4; ++i) {
			sales[i] = 0;
		}
	}
}

// 输入四个元素来初始化
Sales::Sales() {
	using namespace std;
	cout << "输入四个数字：";
	for (int i = 0; i < 4; ++i) {
		cin >> sales[i];
	}
	max = sales[0];
	min = sales[0];
	average = 0;
	for (int i = 0; i < 4; ++i) {
		max = max >= sales[i] ? max : sales[i];
		min = min <= sales[i] ? min : sales[i];
		average += sales[i];
	}
	average /= 4;
}

void Sales::showSales() {
	using namespace std;
	cout << "四个元素分别为：";
	for (int i = 0; i < 4; ++i) {
		cout << sales[i] << ' ';
	}
	cout << endl;
	cout << "最大值为：" << max << endl;
	cout << "最小值为：" << min << endl;
	cout << "平均值为：" << average << endl;
}