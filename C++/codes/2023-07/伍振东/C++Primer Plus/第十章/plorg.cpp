#include"plorg.h"
#include<iostream>
using namespace std;

Plorg::Plorg() {
	strcpy_s(name, "Plorga");
	CI = 50;
}

Plorg::Plorg(int m_CI) {
	strcpy_s(name, "Plorga");
	CI = m_CI;
}

void Plorg::change_CI(int ci) {
	CI = ci;
	show();
}

void Plorg::show()const {
	cout << "Ãû³Æ£º" << name << endl;
	cout << "CIÖµ£º" << CI << endl;
}