#include <iostream>

long double probability(unsigned numbers, unsigned picks);

int main()
{
	using namespace std;
	double total1, choices1, total2, choices2;
	cout << "请分别输入两组数：";
	while ((cin >> total1 >> choices1) && (cin >> total2 >> choices2) && choices1 <= total1 && choices2 <= total2)
	{
		cout << "You have one chance in ";
		cout << probability(total1, choices1) * probability(total2, choices2);  // compute the odds
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";
	return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;  // here come some local variables
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; n--, p--)
		result = result * n / p;
	return result;
}
