#include<iostream>
#include<string>
#include"cow.h"
#include"string2.h"
#include"Stock.h"
#include"Stack.h"

// 第十二章

// 12.1：Cow类实现
void controller12_1() {

	Cow c1;
	c1.ShowCow();
	const char* nm = "xiaoli";
	const char* hb = "swiming";
	double wt = 60.0;
	Cow c2(nm, hb, wt);
	c2.ShowCow();
	const Cow c3("xiaowang", "run", 50);
	c3.ShowCow();
	Cow c4(c3);
	c4.ShowCow();
	c4 = c2;
	c4.ShowCow();
}

// 12.2：String2类
void controller12_2() {
	using namespace std;
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name:";
	String s3;
	std::cout << s2;
	std::cin >> s3;
	s2 = "My name is " + s3;
	std::cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "The String\n" << s2 << "\ncontains " << s2.count('A') << " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light:";
	String ans;
	bool success = false;
	while (cin >> ans) {
		ans.stringlow();
		for (int i = 0; i < 3; ++i) {
			if (ans == rgb[i]) {
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else {
			cout << "try again!\n";
		}
	}
}

// 12.3：测试Stock
void controller12_3()
{
	const int STKS = 4;
	Stock stocks[STKS] =
	{
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		std::cout << stocks[st];
	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topVal(stocks[st]);
	std::cout << "\nMost valuable holding:\n";
	std::cout << *top;
	system("pause");
}

// 12.4：测试Stack
void controller12_4() {
	Stack stk(10);
	stk.push(10);
	stk.push(20);
	stk.push(30);
	std::cout << stk;

	Item a;
	stk.pop(a);
	std::cout << std::endl << stk;
}

int main() {
	//controller12_1();
	//controller12_2();
	//controller12_3();
	controller12_4();
	system("PAUSE");
	return 0;
}