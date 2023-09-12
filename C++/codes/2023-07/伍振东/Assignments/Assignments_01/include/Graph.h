#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
#include<vector>

// 使用结构体保存路径和权重
struct mpath
{
    std::vector<int> m_queue;
    int weight = 0; 
};

// 使用邻接矩阵来对图进行存储
class Graph {
private:
    int _edges;
    // _matrix[i][j]==n，说明存在一条从i指向j的权重为n的边
    int** _matrix;
    // 增加一个数据结构，存储当前有多少路径指向自身
    int* _pre_edges;

public:
    Graph();
    Graph(int m_edges);
    Graph(int** m_matrix, const int length, const int weight);
    Graph(Graph& m_graph);
    // 判断拓扑排序是否已经结束
    bool isEnd();
    ~Graph();
    int returnEdge(){
        return _edges;
    }
    void findTwoPoint(int point1, int point2, mpath path, std::vector<mpath>& res);
    friend std::vector<std::vector<int>> topSort(Graph graph);
    friend void allPath(std::vector<int> nodes, Graph m_graph, int n, int first, int second);
};

void showVector(std::vector<int> mid_node);

#endif