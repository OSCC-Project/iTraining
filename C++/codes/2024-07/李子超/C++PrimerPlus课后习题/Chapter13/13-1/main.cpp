#include <iostream>
#include "cd.h"  // which will contain #include cd.h

void Bravo(const Cd & disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    
    Cd *pcd = &c1;

    std::cout << "Using object directly:\n";
    c1.Report();  // use Cd method
    c2.Report();  // use Classic method

    std::cout << "Using type cd * pointer to objects:\n";
    pcd->Report();  // use Cd method for cd object
    pcd = &c2;
    pcd->Report();  // use Classic method for classic object

    std::cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);

    std::cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}
