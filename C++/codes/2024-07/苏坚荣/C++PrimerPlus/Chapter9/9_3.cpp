#include<iostream>
#include<new>

const int BUF = 512;
char buffer[BUF];

struct chaff {
	char dross[20];
	int slag;
};


int main() {
	using namespace std;
	chaff* pd1, * pd2;
	pd1 = new chaff[2];
	pd2 = new (buffer) chaff[2];
	strcpy_s(pd1[0].dross, 20, "chaff1_1");
	strcpy_s(pd1[1].dross, 20, "chaff1_2");
	strcpy_s(pd2[0].dross, 20, "chaff2_1");
	strcpy_s(pd2[1].dross, 20, "chaff2_2");
	pd1[0].slag = pd2[0].slag = 10;
	pd1[1].slag = pd2[1].slag = 20;

	cout << "Memory addresses:\n" << "    heap: " << pd1 << " static: " << (void*)buffer << endl;
	cout << "Memory contents:\n";
	for (int i = 0; i < 2; i++) {
		cout << pd1[i].dross << " at " << &pd1[i].dross << "; ";
		cout << pd2[i].dross << " at " << &pd2[i].dross << endl;
		cout << pd1[i].slag << " at " << &pd1[i].slag << "; ";
		cout << pd2[i].slag << " at " << &pd2[i].slag << endl;

	}

	return 0;
}