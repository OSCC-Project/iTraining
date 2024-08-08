#pragma once
#include<iostream>

namespace SALES
{
	const int QUARTERS = 4;
	class Sales
	{
	private:
		double _sales[QUARTERS];
		double _average;
		double _max;
		double _min;
	public:
		Sales();
		Sales(const double ar[], int n);
		~Sales();
		void showSales() const;
	};
}