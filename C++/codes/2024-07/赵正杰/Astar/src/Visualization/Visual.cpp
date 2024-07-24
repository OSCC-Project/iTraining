#include "Visual.h"

Visualization::Visualization(Graph* ptr) : _P_Graph(ptr) {}

void Visualization::Put_Visual() {
    int width = _P_Graph->get_Width();
    int length = _P_Graph->get_length();

    for (int ii = 0; ii < (length + 3) * 2; ++ii) {
        std::cout << "-";
    }

    std::cout << std::endl;
    for (int ii = 0; ii < width; ++ii) {
        std::cout << "|  ";
        for (int jj = 0; jj < length; jj++) {
            std::cout << _P_Graph->get_Weight(ii, jj) << " ";

            if (jj == length - 1) {
                std::cout << " |" << std::endl;
            }
        }
    }

    for (int ii = 0; ii < (length + 3) * 2; ++ii) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

Visualization::~Visualization() {}