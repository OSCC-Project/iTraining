#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
	string name;
	string account;
	int money;
public:
	BankAccount(const string& n="",const string& a="",const int &m=0);
	void show() const;
	void save(const int& m);
	void withdraw(const int& m);
};

BankAccount::BankAccount(const string & n, const string & a, const int & m):name(n),account(a),money(m)
{
}

void BankAccount::show() const
{
	cout << "BanAccount:" << endl;
	cout << "name:" << name << endl;
	cout << "account:" << account << endl;
	cout << "money:" << money << endl;
	cout << endl;
}

void BankAccount::save(const int& m)
{
	money += m;
}

void BankAccount::withdraw(const int& m)
{
	if (money < m)
		cout << "money no enough" << endl << endl;
	else
		money -= m;
}
int main()
{
	BankAccount test("lzc", "135", 100);
	test.show();
	test.save(50);
	test.show();
	test.withdraw(200);
	test.withdraw(120);
	test.show();

}
