#include <iostream>
#include "stonewt.h"

void display(const Stonewt& st, int n);

int main()
{
	using namespace std;

	Stonewt incognito = 275; // uses constructor to initialize
	Stonewt wolfe(285.7);    // same as Stonewt wolfe = 285.7;
	Stonewt taft(21, 8);

	incognito.setMode(Stonewt::INT_POUNDS);
	wolfe.setMode(Stonewt::FLOAT_POUNDS);
	taft.setMode(Stonewt::STONE);

	Stonewt test1 = taft * 10;
	Stonewt test2 = incognito + wolfe;
	Stonewt test3 = taft - incognito;

	test1.setMode(Stonewt::STONE);
	test2.setMode(Stonewt::FLOAT_POUNDS);
	test3.setMode(Stonewt::INT_POUNDS);

	cout << "The celebrity weighed ";
	cout << incognito << endl;
	cout << "The detective weighed ";
	cout << wolfe << endl;
	cout << "The President weighed ";
	cout << taft << endl;

	cout << "test1: taft * 10 = " << test1 << endl;
	cout << "test2: incognito + wolfe = " << test2 << endl;
	cout << "test3: taft - incognito = " << test3 << endl;

	incognito = 276.8;       // uses constructor for conversion
	taft = 325;              // same as taft = Stonewt(325);
	cout << "After dinner, the celebrity weighed ";
	cout << incognito << endl;
	cout << "After dinner, the President weighed ";
	cout << taft << endl;
	display(taft, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt& st, int n)
{
	using namespace std;
	for (int i = 0; i < n; i++)
	{
		cout << "Wow! ";
		cout << st << endl;
	}
}
