#include <iostream>
#include "stack.h"

int main()
{
	using namespace std;
	Item po;

	Stack st1(5);
	st1.push(10);
	st1.push(20);
	st1.push(30);

	Stack st2(st1);
	Stack st3 = st1;
	st2.pop(po);
	cout << "PO #" << po << " popped\n";
	st2.pop(po);
	cout << "PO #" << po << " popped\n";

	st3.pop(po);
	cout << "PO #" << po << " popped\n";
	st3.pop(po);
	cout << "PO #" << po << " popped\n";

	return 0;
}
