//
//  person.cpp
//  10-2
//
//  Created by 郭帆 on 2023/7/20.
//

#include <iostream>
#include <cstring>
#include "person.hpp"

using namespace std;

Person::Person(const string &ln, const char *fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    std::cout << "The name format is:" << endl;
    std::cout << fname << "(firstname), ";
    std::cout << lname << "(lastname).";
}

void Person::FormalShow() const
{
    std::cout << "The name format is:" << endl;
    std::cout << lname << "(lastname), ";
    std::cout << fname << "(firstname)." << endl;
}
