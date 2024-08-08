#include <iostream>
#include "golf.h"
int main()
{
	golf garray[5];
	int size = 0;
	for (int i = 0; i < 5; i++) {
		if (setGolf(garray[i])) {
			size++;
			std::cout << "next input:" << std::endl;
		}
		else break;
	}
	for (int i = 0; i < size; i++) {
		showGolf(garray[i]);
	}
}