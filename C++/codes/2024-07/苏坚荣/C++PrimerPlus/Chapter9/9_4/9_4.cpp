#include<iostream>
#include"9_4.h"
namespace SALES {
	void setSales(Sales& s, const double ar[], int n)
	{
		int i = 0;
		double max = 0, min = ar[0], avg = 0, total = 0;
		for (i = 0; i < n; i++) {
			s.sales[i] = ar[i];
			if (ar[i] > max) {
				max = ar[i];
			}
			if (ar[i] < min) {
				min = ar[i];
			}
			total += ar[i];
		}
		s.average = total / n;
		s.max = max;
		s.min = min;
		if (i < 4) {
			for (int j = i; j < 4; j++) {
				s.sales[j] = 0;
			}
		}
	}

	void setSales(Sales& s) {
		using namespace std;
		double max, min, total;
		cout << "请分别输入四个季度的销售额：";
		for (int i = 0; i < 4; i++) {
			cin >> s.sales[i];
		}
		max = min = total = s.sales[0];
		for (int i = 1; i < 4; i++) {
			if (s.sales[i] > max) {
				max = s.sales[i];
			}
			if (s.sales[i] < min) {
				min = s.sales[i];
			}
			total += s.sales[i];
		}
		s.average = total / 4;
		s.max = max;
		s.min = min;
	}

	void showSales(const Sales& s) {
		using namespace std;
		cout << "四个季度的销售额分别为：";
		for (int i = 0; i < 4; i++) {
			cout << s.sales[i] << " ";
		}
		cout << endl;
		cout << "最大值：" << s.max << endl;
		cout << "最小值：" << s.min << endl;
		cout << "平均值：" << s.average << endl;
	}

}

