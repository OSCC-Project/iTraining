//
//  graph.cpp
//  DAG
//
//  Created by 郭帆 on 2023/7/21.
//

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "graph.hpp"

bool Graph::addVertices(int number) {
    if (number <= 0) return false;
    
    // resize existing lines
    for (int i = 0; i < _vertices_count; i++) {
        _edges[i].resize(_vertices_count + number);
    }
    
    // add new lines
    for (int i = 0; i < number; i++) {
        _edges.push_back(std::vector<int>(_vertices_count + number, 0));
    }
    
    // refresh vertices amount
    _vertices_count += number;
    
    return true;
}

bool Graph::insertVertex(int index) {
    if (index < 0 || index > _vertices_count) return false;
    
    // insert column
    for (int i = 0; i < _vertices_count; i++) {
        _edges[i].insert(_edges[i].begin() + index, 0);
    }
        
    // insert row
    _edges.insert(_edges.begin() + index, std::vector<int>(_vertices_count + 1, 0));
    
    // refresh vertices count
    _vertices_count++;
    
    return true;
}

bool Graph::removeVertex(int index) {
    if (index < 0 || index >= _vertices_count) return false;
    
    // remove line
    _edges.erase(_edges.begin() + index);
    
    // remove column
    for (int i = 0; i < _vertices_count-1; i++) {
        _edges[i].erase(_edges[i].begin() + index);
    }
    
    // refresh vertices count
    _vertices_count--;
    
    return true;
}

bool Graph::setEdge(Edge e) {
    if (e.from >= _vertices_count || e.from < 0 ||
        e.to >= _vertices_count || e.to < 0) {
        return false;
    }
    _edges[e.from][e.to] = e.weight;
    return true;
}

bool Graph::setEdge(std::vector<Edge> v) {
    bool result = true;
    for (auto &e : v) {
        if (!setEdge(e)) result = false;
    }
    return result;
}

bool Graph::isDAG() {
    __visited = std::vector<bool>(_vertices_count, false);
    
    int cnt = 0;
    bool finished = false;
    auto edges = _edges;
    while (!finished) {
        bool contain_zero_degree = false;
        for (int i = 0; i < _vertices_count && !__visited[i]; i++) {
            
            // find degree for vetex i
            int degree = 0;
            for (int j = 0; j < _vertices_count; j++) {
                if (edges[j][i] > 0) degree++;
            }
            
            // degree is 0
            if (!degree) {
                contain_zero_degree = true;
                cnt++;
                __visited[i] = true;
                
                // clear degree for vetices from vertex i
                for (int j = 0; j < _vertices_count; j++) {
                    edges[i][j] = 0;
                }
            }
        }
        finished = !contain_zero_degree;
    }
    
    return cnt == _vertices_count;
}

std::priority_queue<Path> Graph::findPath(int from, int to, std::vector<int> pathpoint) {
    std::priority_queue<Path> result;
    
    __visited = std::vector<bool>(_vertices_count, false);
    __next = std::vector<int>(_vertices_count, 0);
    
    DFS(from, to, pathpoint, result);
    
    return result;
}

void Graph::DFS(int from, int to, std::vector<int> &pathpoint, std::priority_queue<Path> &result) {
    __visited[from] = true;
    if (from == to) { // path found
        Path p = {};
        int k = 0;
        
        // record pathpoint
        while(k != to) {
            p.pathpoint.push_back(k);
            k = __next[k];
        }
        p.pathpoint.push_back(k);
        
        // calculate path weight
        for (int i = 0; i < p.pathpoint.size() - 1; i++) {
            p.weight += _edges[p.pathpoint[i]][p.pathpoint[i+1]];
        }
        
        // search if middle point in path
        std::unordered_set<int> s;
        for (auto point : p.pathpoint) {
            s.emplace(point);
        }
        bool is_match = true;
        for (auto m : pathpoint) {
            if (s.find(m) == s.end()) {
                is_match = false;
            }
        }
        
        // valid path, push to result
        if (is_match) {
            result.push(p);
        }
        
        return;
    }

    // DFS
    for (int j = 0; j < _vertices_count; j++) {
        if(__visited[j] == false && _edges[from][j] != 0) {
            __next[from] = j;
            DFS(j, to, pathpoint, result);
            __visited[j] = false;
        }
    }
}
