#include "9-4-sales.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
namespace SALES
{
	void setSales(Sales & s, const double ar[], int n)
	{
		double sum = 0.0;
		s.max = ar[0];
		s.min = ar[0];
		for (int i = 0; i < QUARTERS; i++) {
			if (i < n) {
				s.sales[i] = ar[i];
				sum += ar[i];
				s.max = s.max > ar[i] ? s.max : ar[i];
				s.min = s.min < ar[i] ? s.min : ar[i];
			}
			else {
				s.sales[i] = 0.0;
			}
			s.average = sum / QUARTERS;
		}
	}


	void setSales(Sales & s)
	{
		double total = 0.0;
		std::cout << "Enter sales for 4 quarters" << endl;
		for (int i = 0; i < QUARTERS; i++)
		{
			std::cout << "Quarter " << (i + 1) << ": ";
			std::cin >> s.sales[i];
			total += s.sales[i];

			if (i == 0)
			{
				s.max = s.min = s.sales[i];
			}
			else
			{
				if (s.sales[i] > s.max)
					s.max = s.sales[i];
				if (s.sales[i] < s.min)
					s.min = s.sales[i];
			}
		}

		s.average = total / QUARTERS;
	}

	void showSales(const Sales & s)
	{
		cout << "Sales:" << endl;
		for (int i = 0; i < 4; i++) {
			cout << "Quarter" << i + 1 << ":" << s.sales[i] << endl;
		}
		cout << "max:" << s.max << endl;
		cout << "min:" << s.min << endl;
		cout << "average:" << s.average << endl;
	}
}