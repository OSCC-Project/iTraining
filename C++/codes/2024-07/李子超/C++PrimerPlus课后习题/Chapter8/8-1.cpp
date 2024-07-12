#include <iostream>
using std::cout;
using std::endl;
using std::cin;
void print_str(char *s, int i = 0);

void print_str(char * s, int i)
{
	static int total = 0;
	total++;
	if (i == 0) {
		cout << s;
	}
	else {
		for (int j = 0; j < total; j++)
			cout << s << endl;
	}
}
int main() {
	char str[6] = "abced";
	int i;
	while (cin >> i) {
		print_str(str, i);
	}
}
