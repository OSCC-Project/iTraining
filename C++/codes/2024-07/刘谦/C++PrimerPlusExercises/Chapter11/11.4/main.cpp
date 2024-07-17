#include <iostream>
#include "mytime3.h"

int main() {
    Time t1(1, 30);  
    Time t2(5, 40);  

    std::cout << "Time 1: " << t1 << std::endl;
    std::cout << "Time 2: " << t2 << std::endl;

    Time t3 = t1 + t2;
    std::cout << "Sum: " << t3 << std::endl;

    Time t4 = t1 - t2;
    std::cout << "Difference: " << t4 << std::endl;

    Time t5 = t1 * 2.5;  
    std::cout << "Time 1 multiplied by 3: " << t5 << std::endl;

    return 0;
}
