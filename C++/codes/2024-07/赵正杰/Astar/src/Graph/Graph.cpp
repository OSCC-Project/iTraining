#include "Graph.h"

Graph::Graph(int w, int h) : _width(w), _length(h), _Adj_Graph(w, std::vector<int>(_length, 1)) {}

void Graph::set_Weight() {
    for (int ii = 0; ii < _width; ++ii) {
        printf("请输入第%d行的所有元素(ex:1 2 3 4 5,默认为长8宽4):\n", ii+1);
        for (int jj = 0; jj < _length; ++jj) {
            std::cin >> _Adj_Graph[ii][jj];
        }
    }
}

int Graph::get_Width() {
    return _width;
}

int Graph::get_length() {
    return _length;
}

int Graph::get_Weight(int x, int y) {
    return _Adj_Graph[x][y];
}

Graph::~Graph() {}