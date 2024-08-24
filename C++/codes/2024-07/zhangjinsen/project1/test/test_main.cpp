#include <gtest/gtest.h>

// 包含要测试的头文件
#include "../include/project/a_.h"

#include "../include/project/gra.h"

// 示例测试
TEST(ASTAR, Assertions) {
     Grid_ gra(4,8);
    gra.setValue(0,4,1);
    gra.setValue(0,5,1);
    gra.setValue(0,6,1);
    
    gra.setValue(0,7,1);
    gra.setValue(1,7,1);
    
    gra.setValue(1,6,1);
    
    gra.setValue(1,5,1);
    gra.setValue(2,1,1);
    gra.setValue(2,0,1);
    gra.setValue(2,3,1);
    gra.setValue(2,4,1);
    gra.setValue(3,0,1);
    std::pair<int,int> start=std::make_pair(0,0);
    std::pair<int,int> goal=std::make_pair(3,7);
    AStarAlgorithm astar;
    std::vector<std::pair<int, int>> path = astar.findPath(gra, start, goal);
    
    EXPECT_EQ(path.size(), 10);
    EXPECT_EQ(1, 1);
    
}
TEST(ASTAR, Assertions2) {
    Grid_ gra(4, 8);
    gra.setValue(0, 4, 1);
    gra.setValue(0, 5, 1);
    gra.setValue(0, 6, 1);
    gra.setValue(0, 7, 1);
    gra.setValue(1, 7, 1);
    gra.setValue(1, 6, 1);
    gra.setValue(1, 5, 1);
    gra.setValue(2, 1, 1);
    gra.setValue(2, 0, 1);
    gra.setValue(2, 3, 1);
    gra.setValue(2, 4, 1);
    gra.setValue(3, 0, 1);

    std::pair<int, int> start = std::make_pair(0, 0);
    std::pair<int, int> goal = std::make_pair(3, 7);
    AStarAlgorithm astar;
    std::vector<std::pair<int, int>> path = astar.findPath(gra, start, goal);

    // 期望的路径长度
    EXPECT_EQ(path.size(), 10);

}
// 运行所有测试
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
