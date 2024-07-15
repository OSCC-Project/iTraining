#include"10_1.h"
#include<iostream>


int main() {
	Account user1;
	Account user2("SuJianrong", "202407", 10000);

	user1.showAccount();
	user2.showAccount();

	user1.pushMoney(2000);
	user1.showAccount();

	user2.pullMoney(200);
	user2.showAccount();

	return 0;
}