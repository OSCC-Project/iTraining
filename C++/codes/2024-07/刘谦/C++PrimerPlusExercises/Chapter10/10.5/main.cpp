#include <iostream>
#include <cstring>
#include "stack.hpp"

typedef customer Item;  

int main() {
    Stack stack;
    Item cust;
    double totalPayment = 0.0;
    char input[35];

    while (true) {
        std::cout << "Enter fullname (or 'q' to quit): ";
        std::cin.getline(input, 35);

        if (strcmp(input, "q") == 0) {
            break;
        }

        strcpy(cust.fullname, input);

        std::cout << "Enter payment: ";
        std::cin >> cust.payment;
         std::cin.ignore();  // 忽略cin保留的换行符

        if (stack.push(cust)) {
            std::cout << "Customer added to stack.\n";
        } else {
            std::cout << "Failed to add customer.\n";
        }
    }

    while (!stack.isempty()) {
        stack.pop(cust);
        totalPayment += cust.payment;
        std::cout << "Removed customer: " << cust.fullname << ", Payment: " << cust.payment << "\n";
    }

    std::cout << "Total payment: " << totalPayment << std::endl;

    return 0;
}