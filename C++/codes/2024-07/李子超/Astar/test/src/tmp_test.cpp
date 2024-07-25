#include "Astar/Astar.hpp"
#include "Astar/Point.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <iterator>


TEST(AstarTest, CheckPath) {

    std::vector<std::vector<int>> g = {
        {0,0,0,0,1,1,1,1},
        {0,0,0,0,0,1,1,1},
        {1,1,0,1,1,0,0,0},
        {1,0,0,0,0,0,0,0},
    };
    Map map(4, 8, g);
    map.showMap();

    Astar astar;
    // 设置起始和结束点
    Point *start = new Point(0, 0);
    Point *end = new Point(3, 7);

    // A*算法
    auto path=astar.findPath(start, end, map);
    std::list<Point*> resultpath;
    resultpath.push_back(new Point(0,0));
    resultpath.push_back(new Point(0,1));
    resultpath.push_back(new Point(1,2));
    resultpath.push_back(new Point(1,3));
    resultpath.push_back(new Point(1,4));
    resultpath.push_back(new Point(2,5));
    resultpath.push_back(new Point(2,6));
    resultpath.push_back(new Point(3,7));

    auto it1 = path.begin();
    auto it2 = resultpath.begin();

    for (; it1 != path.end() && it2 != resultpath.end(); ++it1, ++it2) {
        EXPECT_EQ((*it1)->getX(),(*it2)->getX());
        EXPECT_EQ((*it1)->getY(),(*it2)->getY());
    }

    system("pause");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
