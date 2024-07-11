#include <iostream>
double caculate(double a, double b,double (*ptr)(double,double));
inline double add(double x, double y)
{
	std::cout << "add: ";
	return x + y;
}
inline double sub(double x, double y)
{
	std::cout << "sub:  ";
	return x - y;
}
int main() {
	int x, y;
	double(*pf[2]) (double, double) = { add,sub };
	while (std::cin >> x >> y) {
		double a1=caculate(x, y, pf[0]);
		std::cout << a1 << std::endl;
		double a2 = caculate(x, y, pf[1]);
		std::cout << a2 << std::endl;
	}
	
}
double caculate(double a, double b, double(*ptr)(double, double))
{
	return (*ptr)(a, b);
}
