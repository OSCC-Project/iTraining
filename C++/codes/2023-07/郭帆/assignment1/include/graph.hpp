//
//  graph.hpp
//  DAG
//
//  Created by 郭帆 on 2023/7/21.
//

#ifndef graph_hpp
#define graph_hpp

#include <vector>
#include <queue>

struct Edge {
    int from = 0;
    int to = 0;
    int weight = 0;
};

struct Path {
    int weight;
    std::vector<int> pathpoint;
    
    friend bool operator<(Path p1, Path p2) { return p1.weight < p2.weight; }
};

class Graph {
private:
    int _vertices_count;
    std::vector<std::vector<int>> _edges;
    
public:
    Graph(int size, std::vector<std::vector<int>> edges) : _vertices_count(size), _edges(edges) {}
    Graph(int size = 0) {
        *this = Graph(size, std::vector<std::vector<int>>(size, std::vector<int>(size, 0)));
    }
    
    bool addVertices(int number);
    bool insertVertex(int index);
    bool removeVertex(int index);
    
    bool setEdge(Edge e);
    bool setEdge(std::vector<Edge> v);
    
    bool isDAG();
    std::priority_queue<Path> findPath(int from, int to, std::vector<int> pathpoint);
private:
    std::vector<bool> __visited;
    std::vector<int> __next;
    void DFS(int from, int to, std::vector<int> &pathpoint, std::priority_queue<Path> &result);
};

#endif /* graph_hpp */
