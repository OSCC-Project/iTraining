//版本2
#include<iostream>
#include<string>
using namespace std;

const int Seasons = 4;
const char* Snames[] = { "Spring", "Summer", "Fall", "Winter" };

struct S_exp {
	double expense[4];
};

void fill(S_exp& s);
void show(S_exp& s);

int main() {
	S_exp s;
	fill(s);
	show(s);


	return 0;
}

void fill(S_exp& s) {
	for (int i = 0; i < Seasons; i++) {
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> s.expense[i];
	}
}

void show(S_exp& s) {
	double total = 0.0;
	cout << "EXPENSES" << endl;
	for (int i = 0; i < Seasons; i++) {
		cout << Snames[i] << ": $" << s.expense[i] << endl;
		total += s.expense[i];
	}
	cout << "Total Expenses: $" << total << endl;
}

//版本1
/*
#include<iostream>
#include<string>
using namespace std;

const int Seasons = 4;
const char* Snames[] = { "Spring", "Summer", "Fall", "Winter" };

void fill(double a[]);
void show(double a[]);

int main() {
	double expense[4];
	fill(expense);
	show(expense);


	return 0;
}

void fill(double a[]) {
	for (int i = 0; i < Seasons; i++) {
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> a[i];
	}
}

void show(double a[]) {
	double total = 0.0;
	cout << "EXPENSES" << endl;
	for (int i = 0; i < Seasons; i++) {
		cout << Snames[i] << ": $" << a[i] << endl;
		total += a[i];
	}
	cout << "Total Expenses: $" << total << endl;
}
*/