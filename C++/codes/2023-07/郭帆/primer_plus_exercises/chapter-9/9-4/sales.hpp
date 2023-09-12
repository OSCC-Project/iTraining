//
//  sales.hpp
//  9-4
//
//  Created by 郭帆 on 2023/7/20.
//

#ifndef sales_hpp
#define sales_hpp

namespace SALES {

const int QUARTERS = 4;
struct Sales {
    double sales[QUARTERS];
    double average;
    double max;
    double min;
};

void setSales(Sales & s, const double ar[], int n);
void setSales(Sales & s);
void showSales(const Sales & s);

}

#endif /* sales_hpp */
