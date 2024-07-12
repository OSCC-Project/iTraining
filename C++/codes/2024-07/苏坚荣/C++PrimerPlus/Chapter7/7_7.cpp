#include <iostream>
const int Max = 5;

// function prototypes
double* fill_array(double ar[]);
void show_array(const double* begin, const double* end); // don't change data
void revalue(double r, double* begin, double* end);


int main()
{
	using namespace std;
	double properties[Max];

	double* last = fill_array(properties);	//last是指向数组末尾的指针

	show_array(properties, last);
	if (last > properties)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, last);
		show_array(properties, last);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();
	return 0;
}

double* fill_array(double ar[])
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0) // signal to terminate
			break;
		ar[i] = temp;
	}
	return ar + i;
}

// the following function can use, but not alter,
// the array whose address is ar
void show_array(const double* begin, const double* end)
{
	using namespace std;
	const double* pt;
	int i = 1;
	for (pt = begin; pt != end; pt++) {
		cout << "Property #" << i++ << ": $";
		cout << *pt << endl;
	}
}

// multiplies each element of ar[] by r
void revalue(double r, double* begin, double* end)
{
	double* pt;
	for (pt = begin; pt != end; pt++)
		*pt *= r;
}
