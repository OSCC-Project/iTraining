//
//  main.cpp
//  assignment3
//
//  Created by 郭帆 on 2023/7/25.
//

#include <iostream>

#include <gtest/gtest.h>

#include "point.h"
#include "gridmap.h"
#include "astar.h"

using namespace std;

TEST(gridmapTest, test0) {
    vector<vector<double>> obstacles {
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { 0, 0, 0, 0, 0, INFINITY, INFINITY, INFINITY },
        { INFINITY, INFINITY, 0, INFINITY, INFINITY, 0, 0, 0 },
        { INFINITY, 0, 0, 0, 0, 0, 0, 0 }
    };

    gridmap::Map<astar::Node> map(obstacles);

    // std::vector<T> & gridmap::Map::operator[](int index);
    // bool gridmap::Node::isWalkable() const;
    EXPECT_TRUE(map[0][0].isWalkable());
    EXPECT_FALSE(map[1][5].isWalkable());

    // T & gridmap::Map::operator[](const point::Point2i & p);
    // double gridmap::Node::get_walk_cost();
    point::Point2i testing_position{ 2, 2 };
    EXPECT_EQ(0, map[testing_position].get_walk_cost());
    double inf_walk_cost = map[{ 3, 0 }].get_walk_cost();
    EXPECT_LT(1000000, inf_walk_cost);

    // int gridmap::Node::x() const;
    // int gridmap::Node::y() const;
    EXPECT_EQ(map[2][3].x(), 2);
    EXPECT_EQ(map[2][3].y(), 3);

    // virtual bool gridmap::Node::operator==(const Node & n) const;
    EXPECT_TRUE(map[3][3] == gridmap::Node({ 3, 3 }));
    EXPECT_FALSE(map[3][3] == gridmap::Node({ 2, 3 }));

    // std::vector<T *> gridmap::Map::getNeighbours(const point::Point2i & p);
    auto neighbours = map.getNeighbours({ 2, 2 });
    ASSERT_EQ(neighbours.size(), 8);
    EXPECT_FALSE(neighbours[3]->isWalkable());

    // std::vector<T *> gridmap::Map::getNeighbours(const T & n);
    neighbours = map.getNeighbours(map[0][0]);
    EXPECT_EQ(neighbours.size(), 3);

    // void gridmap::Node::set_walk_cost(double cost);
    map[1][4].set_walk_cost(0.2);
    EXPECT_EQ(map[1][4].get_walk_cost(), 0.2);
}

TEST(astarTest, test0) {
    vector<vector<double>> obstacles {
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { INFINITY, INFINITY, 0, INFINITY, INFINITY, 0, 0, 0 },
        { INFINITY, 0, 0, 0, 0, 0, 0, 0 }
    };

    gridmap::Map<astar::Node> map(obstacles);
    point::Point2i starting_position{ 0, 0 };
    point::Point2i ending_position{ 3, 7 };
    astar::PathFinder pathfinder(map, starting_position, ending_position);

    // std::vector<Node *> astar::PathFinder::findPath(gridmap::Map<Node> & map, Node * start_node, Node * target_node);
    auto path = pathfinder.findPath();
    bool is_same_position = path[0]->get_position() == point::Point2i({ 0, 0 });
    EXPECT_TRUE(is_same_position);
    is_same_position = path[2]->get_position() == point::Point2i({ 2, 2 });
    EXPECT_TRUE(is_same_position);

    // void astar::PathFinder::set_starting_position(const point::Point2i starting_position);
    pathfinder.set_starting_position({ 1, 3 });
    path = pathfinder.findPath();
    is_same_position = path[0]->get_position() == point::Point2i({ 1, 3 });
    EXPECT_TRUE(is_same_position);

    // void astar::PathFinder::set_ending_position(const point::Point2i ending_position);
    pathfinder.set_ending_position({ 2, 5 });
    path = pathfinder.findPath();
    is_same_position = (*(path.end()-1))->get_position() == point::Point2i({ 2, 5 });
}

TEST(astarTest, timetest) {
    vector<vector<double>> obstacles {
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { INFINITY, INFINITY, 0, INFINITY, INFINITY, 0, 0, 0 },
        { INFINITY, 0, 0, 0, 0, 0, 0, 0 }
    };

    gridmap::Map<astar::Node> map(obstacles);
    astar::PathFinder pathfinder(map, { 0, 0 }, { 3, 7 });

    for (int i = 0; i < 1000; ++i) {
        pathfinder.findPath();
    }
}

int main(int argc, char ** argv) {
    vector<vector<double>> obstacles {
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY },
        { 0, 0, 0, 0, 0.2, INFINITY, INFINITY, INFINITY },
        { INFINITY, INFINITY, 0, INFINITY, INFINITY, 0, 0, 0 },
        { INFINITY, 0, 0, 0, 0, 0, 0, 0 }
    };
    
    gridmap::Map<astar::Node> m(obstacles);
    
    cout << m << endl;
    
    point::Point2i starting_position{ 0, 0 };
    point::Point2i ending_position{ 3, 7 };
    
    auto path = astar::PathFinder::findPath(m, starting_position, ending_position);
    astar::PathFinder::showPath(m, path);
    
    m[3][5].set_walk_cost(0.4);
    
    path = astar::PathFinder::findPath(m, starting_position, ending_position);
    astar::PathFinder::showPath(m, path);
    
    starting_position = {1, 0};
    ending_position = {2, 6};
    
    path = astar::PathFinder::findPath(m, starting_position, ending_position);
    astar::PathFinder::showPath(m, path);
    
    m[1][3].set_walk_cost(0.5);
    
    path = astar::PathFinder::findPath(m, starting_position, ending_position);
    astar::PathFinder::showPath(m, path);
    
    m[1][4].set_walk_cost(0.8);
    
    path = astar::PathFinder::findPath(m, starting_position, ending_position);
    astar::PathFinder::showPath(m, path);

    // big map
    vector<vector<double>> big_map_data {
        { 0, 0, 0, 0, INFINITY, INFINITY, INFINITY, INFINITY, 0, 0 },
        { 0, 0, 0, 0, 0.2, INFINITY, INFINITY, INFINITY, 0, 0 },
        { INFINITY, INFINITY, 0, INFINITY, INFINITY, INFINITY, 0, 0, 0, 0 },
        { INFINITY, 0.2, 0, 0, INFINITY, INFINITY, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.5, 0.9, 1, 1, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.5, 0.9, 1, 1, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.5, 0.9, 1, 1, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.5, 0.9, 1, 1, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.5, 0.9, 1, 1, INFINITY, 0, 0, 0 },
        { INFINITY, 0.2, 0.2, 0.2, 0, 0, 0, 0, 0, 0 }
    };
    gridmap::Map<astar::Node> big_map(big_map_data);

    cout << big_map << endl;

    astar::PathFinder pf1(big_map, { 1, 0 }, { 0, 9 });
    pf1.showPath(pf1.findPath());

    pf1.set_starting_position({ 4, 5 });
    pf1.set_ending_position({ 2, 6 });
    pf1.showPath(pf1.findPath());
    
    // google test
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
