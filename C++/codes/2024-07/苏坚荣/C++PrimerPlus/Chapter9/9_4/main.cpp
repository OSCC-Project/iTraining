#include<iostream>
#include"9_4.h"
using namespace SALES;

int main() {
	Sales s1, s2;
	const double arr[3] = { 100.0,200.0,300.0 };
	setSales(s1, arr, 3);
	setSales(s2);
	showSales(s1);
	showSales(s2);
	return 0;
}