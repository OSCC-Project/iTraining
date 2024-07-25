#include <iostream>
#include "9-4-sales.h"
using namespace SALES;
using std::cin;
using std::cout;
using std::endl;
int main()
{
	Sales s1;
	Sales s2;
	const double arr[3] = { 2.1,3.2,6.5 };
	setSales(s1, arr, 3);
	showSales(s1);
	setSales(s2);
	showSales(s2);

}