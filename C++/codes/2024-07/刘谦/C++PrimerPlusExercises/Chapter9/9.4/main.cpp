// main.cpp
#include <iostream>
#include "sales.h"

using  namespace SALES;

int main(){
    Sales s1, s2;

    setSales(s1);

    const double salesData[QUARTERS] = {300.0, 500.0, 250.0, 300.0};
    setSales(s2, salesData, QUARTERS);

    std::cout << "Sales for s1:" << std::endl;
    showSales(s1);
    std::cout << std::endl;

    std::cout << "Sales for s2:" << std::endl;
    showSales(s2);

    return 0;
}
