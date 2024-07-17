#include<iostream>
#include"10_4.h"
using namespace SALES;

int main() {
	const double arr[3] = { 100.0,200.0,300.0 };
	Sales s1(arr, 3);
	Sales s2 = Sales();
	s1.showSales();
	s2.showSales();
	return 0;
}