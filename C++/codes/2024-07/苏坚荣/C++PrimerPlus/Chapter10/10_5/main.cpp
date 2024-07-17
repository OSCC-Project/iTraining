// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>    // or ctype.h
#include "10_5.h"

int main()
{
	using namespace std;
	Stack st;        // create an empty stack
	char ch;
	customer po;
	cout << "Please enter A to add a purchase order,\n"
		<< "P to process a PO, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin.get(po.fullname, 35);
			cout << "Enter a PO payment to add: ";
			cin >> po.payment;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else {
				st.pop(po);
				cout << po.fullname << "已出栈，payment的值添加到总数中" << endl;
				st.showTotal();
			}
			break;
		}
		cout << "Please enter A to add a purchase order,\n"
			<< "P to process a PO, or Q to quit.\n";
	}
	cout << "Bye\n";
	return 0;
}
