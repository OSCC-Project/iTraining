#include"12_1.h"

int main() {
	Cow c1;
	Cow c2("sujianrong", "basketball", 55);
	Cow c3(c1);
	Cow c4 = c2;
	c1.ShowCow();
	c2.ShowCow();
	c3.ShowCow();
	c4.ShowCow();
	return 0;
}