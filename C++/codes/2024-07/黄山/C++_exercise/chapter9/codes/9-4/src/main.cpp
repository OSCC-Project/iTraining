#include"sales.h"

int main(int argc, char** argv){
    SALES::Sales s1, s2;
    double example_sales[5] = {3.4, 6.7, -0.3, -5.4, 2.5};
    SALES::setSales(s1, example_sales, 5);
    SALES::setSales(s2);
    SALES::showSales(s1);
    SALES::showSales(s2);
}