//
//  main.cpp
//  DAG
//
//  Created by 郭帆 on 2023/7/21.
//

#include <iostream>
#include <gtest/gtest.h>
#include "include/graph.hpp"

using namespace std;

void show_path(priority_queue<Path> path) {
    cout << path.size() << " paths in total. " << endl;
    while (!path.empty()) {
        Path p = path.top();
        for (auto v : p.pathpoint) {
            cout << v << "->";
        }
        cout << " w: " << p.weight << endl;
        path.pop();
    }
    cout << endl;
}

TEST(testCase, test0) {
    Graph g(6);
    
    g.setEdge({
        {0, 1, 5},
        {0, 3, 4},
        {0, 2, 5},
        {1, 3, 1},
        {2, 4, 7},
        {3, 4, 2},
        {3, 5, 7},
        {4, 5, 1}
    });
    
    EXPECT_EQ(g.findPath(0, 5, {3}).size(), 4);
}

int main(int argc, char ** argv) {
    Graph g(5);
    
    g.setEdge({
        {0, 1, 5},
        {0, 3, 4},
        {0, 2, 5},
        {1, 3, 1},
        {2, 4, 7},
        {3, 4, 2}
    });
    
    g.addVertices(1);
    
    g.setEdge({3, 5, 7});
    g.setEdge({4, 5, 1});
    
    auto path = g.findPath(0, 5, {3});
    show_path(path);
    
    path = g.findPath(0, 5, {});
    show_path(path);
    
    path = g.findPath(0, 5, {1, 4});
    show_path(path);
    
    cout << "DAG? " << g.isDAG() << endl;
    g.setEdge({4, 0, 3});
    cout << "DAG? " << g.isDAG() << endl;

    // google test
    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}
