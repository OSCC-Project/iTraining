#include "golf.h"
#include <string.h>
#include <iostream>
#include <string>
void setGolf(golf & g, const char * name, int hc)
{
	strncpy_s(g.fullname, name,Len-1);
	g.fullname[Len - 1] = '\0';
	g.handicap = hc;
}

int setGolf(golf & g)
{
	std::cout << "Enter fullname: ";
	std::cin.getline(g.fullname, Len);
	if (strlen(g.fullname) == 0) {
		return 0;
		std::cout << "no name" << std::endl;
	}
	std::cout << "Enter handicap: ";
	std::cin >> g.handicap;
	std::cin.ignore();  
	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showGolf(const golf & g)
{
	std::cout << "golf message:" << std::endl;
	std::cout << "fullname:" << g.fullname << std::endl;
	std::cout << "handicap:" << g.handicap << std::endl;
}

