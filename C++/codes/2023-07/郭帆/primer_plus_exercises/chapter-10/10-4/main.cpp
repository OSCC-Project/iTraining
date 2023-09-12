#include <iostream>
#include "sales.hpp"

int main() {
    const double temp[4] = {1.0, 2.0, 3.0, 4.0};
    SALES::Sales objects[2] = {
        SALES::Sales(),
        SALES::Sales(temp, 4)
    };

    objects[0].show();
    objects[1].show();
    std::cout << "Bye." << std::endl;

    return 0;
}
