#include <iostream>
#include <cstring>   // for strlen(), strcpy()

struct stringy {
	char* _str;       // points to a string
	int _ct;          // length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
void set(stringy& b, const char* t);
void show(const stringy& b, int n = 1);
void show(const char t[], int n = 1);

int main() {
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);  // first argument is a reference,
						  // allocates space to hold copy of testing,
						  // sets str member of beany to point to the
						  // new block, copies testing to new block,
						  // and sets ct member of beany
	show(beany);          // prints member string once
	show(beany, 2);       // prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);        // prints testing string once
	show(testing, 3);     // prints testing string thrice
	show("Done!");
	return 0;
}

void set(stringy& b, const char* test) {
	b._ct = strlen(test);
	b._str = new char[b._ct + 1];
	strcpy_s(b._str, b._ct + 1, test);
}

void show(const stringy& b, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << b._str << std::endl;
	}
}

void show(const char t[], int n) {
	for (int i = 0; i < n; i++) {
		std::cout << t << std::endl;
	}
}

