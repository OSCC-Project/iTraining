#include<iostream>
#include<vector>
#include "Graph.h"

Graph::Graph() {
    _edges = 0;
    _matrix = new int* [1];
    _matrix[0] = new int[1];
    _matrix[0][0] = 0;
    _pre_edges = new int[1];
    _pre_edges[0] = 0;
}

Graph::Graph(int m_edges) {
    _edges = m_edges;
    _pre_edges = new int[m_edges];
    for (int i = 0; i < m_edges; ++i) {
        _pre_edges[i] = 0;
    }
    _matrix = new int* [_edges];
    for (int i = 0; i < _edges; ++i) {
        _matrix[i] = new int[_edges];
        for (int j = 0; j < _edges; ++j) {
            _matrix[i][j] = 0;
        }
    }
}

// 拷贝构造函数
Graph::Graph(int** m_matrax, const int length, const int weight) {
    _edges = length;
    _matrix = new int* [length];
    _pre_edges = new int[length];
    for (int i = 0; i < length; ++i) {
        _pre_edges[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        _matrix[i] = new int[weight];
        for (int j = 0; j < weight; ++j) {
            _matrix[i][j] = m_matrax[i][j];
            if (_matrix[i][j] != 0) {
                _pre_edges[j] += 1;
            }
        }
    }
}

// 赋值构造函数
Graph::Graph(Graph& m_graph) {

    _edges = m_graph._edges;
    _pre_edges = new int[_edges];
    _matrix = new int* [_edges];
    for (int i = 0; i < _edges; ++i) {
        _pre_edges[i] = m_graph._pre_edges[i];
        _matrix[i] = new int[_edges];
        for (int j = 0; j < _edges; ++j) {
            _matrix[i][j] = m_graph._matrix[i][j];
        }
    }
}

Graph::~Graph() {
    for (int i = 0; i < _edges; ++i) {
        delete[]_matrix[i];
    }
    delete[]_matrix;
    delete[]_pre_edges;
}

bool Graph::isEnd() {
    for (int i = 0; i < _edges; ++i) {
        if (_pre_edges[i] != -1) {
            return false;
        }
    }
    return true;
}
