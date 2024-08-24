/**
 * @file test_case.cpp
 * @brief 这个文件是测试 Astar 类的单元测试模块示例
 * 
 * 主要是对是否能够正确找到邻居节点进行测试
 */
#include <gtest/gtest.h>
#include "/home/mrlris/iTraining/C++/codes/2024-07/赵正杰/Astar/src/Algorithm/Astar.h"

//!当前模块是测试 Astar 类的单元测试模块示例

//!测试 Find_neighbors 函数是否能正确找到邻居节点
TEST(AstarTest, FindNeighborsCorrectSize) {
    Graph graph(5, 5); //!创建一个 5x5 的图
    Astar astar;       //!创建 Astar 类的一个实例

    //! 测试 current 在左上角 (0,0)
    Point current1(0, 0);
    std::vector<Point> neighbors1 = astar.Find_neighbors(current1, graph);
    EXPECT_NE(neighbors1.size(), 4);

    //! 测试 current 在右上角 (4,0)
    Point current2(graph.get_Width() - 1, 0);
    std::vector<Point> neighbors2 = astar.Find_neighbors(current2, graph);
    EXPECT_NE(neighbors2.size(), 4);

    //! 测试 current 在左下角 (0,4)
    Point current3(0, graph.get_length() - 1);
    std::vector<Point> neighbors3 = astar.Find_neighbors(current3, graph);
    EXPECT_NE(neighbors3.size(), 4);

    //! 测试 current 在右下角 (4,4)
    Point current4(graph.get_Width() - 1, graph.get_length() - 1);
    std::vector<Point> neighbors4 = astar.Find_neighbors(current4, graph);
    EXPECT_NE(neighbors4.size(), 4);

    //! 测试 current 在非边界点 (2,2)
    Point current5(2, 2);
    std::vector<Point> neighbors5 = astar.Find_neighbors(current5, graph);
    if (current5.first == 0 || current5.first == graph.get_Width() - 1 || 
        current5.second == 0 || current5.second == graph.get_length() - 1) {
        EXPECT_NE(neighbors5.size(), 4);
    } else {
        EXPECT_EQ(neighbors5.size(), 4);
    }
}

TEST(AstarTest, FindNeighborsCorrectSize2) {
    Graph graph(5, 5); //!创建一个 5x5 的图
    Astar astar;       //!创建 Astar 类的一个实例

    //! 测试 current 在左上角 (0,0)
    Point current1(0, 0);
    std::vector<Point> neighbors1 = astar.Find_neighbors(current1, graph);
    EXPECT_NE(neighbors1.size(), 4);

    //! 测试 current 在右上角 (4,0)
    Point current2(graph.get_Width() - 1, 0);
    std::vector<Point> neighbors2 = astar.Find_neighbors(current2, graph);
    EXPECT_NE(neighbors2.size(), 4);

    //! 测试 current 在左下角 (0,4)
    Point current3(0, graph.get_length() - 1);
    std::vector<Point> neighbors3 = astar.Find_neighbors(current3, graph);
    EXPECT_EQ(neighbors3.size(), 4);

    //! 测试 current 在右下角 (4,4)
    Point current4(graph.get_Width() - 1, graph.get_length() - 1);
    std::vector<Point> neighbors4 = astar.Find_neighbors(current4, graph);
    EXPECT_NE(neighbors4.size(), 4);

    //! 测试 current 在非边界点 (2,2)
    Point current5(2, 2);
    std::vector<Point> neighbors5 = astar.Find_neighbors(current5, graph);
    if (current5.first == 0 || current5.first == graph.get_Width() - 1 || 
        current5.second == 0 || current5.second == graph.get_length() - 1) {
        EXPECT_NE(neighbors5.size(), 4);
    } else {
        EXPECT_EQ(neighbors5.size(), 4);
    }
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
