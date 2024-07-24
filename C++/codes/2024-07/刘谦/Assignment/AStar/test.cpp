#include "gtest/gtest.h"
#include "GridMap.h"
#include "AStarAlgorithm.h"
#include "MapVisualizer.h"

void RandomMap(GridMap& map, Node& start, Node& goal);

TEST(AStarTest, FindsPath) {
    GridMap map(10, 10);
    Node start(0, 0), goal(9, 9);
    RandomMap(map, start, goal);

    AStarAlgorithm astar;
    auto path = astar.findPath(map, start, goal);

    ASSERT_FALSE(path.empty());

    ASSERT_EQ(path.front(), start);

    ASSERT_EQ(path.back(), goal);

    for (const Node& node : path) {
        ASSERT_TRUE(map.isWithinBounds(node.x, node.y));
        ASSERT_FALSE(map.isObstacle(node.x, node.y));
    }
}

TEST(AStarTest, NoPath) {
    GridMap map(10, 10);
    Node start(0, 0);
    Node goal(9, 9);

    for (int i = 0; i < 10; ++i) {
        map.setObstacle(i, 5);
    }

    AStarAlgorithm astar;
    auto path = astar.findPath(map, start, goal);

    ASSERT_TRUE(path.empty());
}

int main(int argc, char **argv) {

    GridMap map(10, 10);
    Node start(0, 0), goal(0, 0);
    // map.setObstacle(3, 3);
    // map.setObstacle(3, 4);
    // map.setObstacle(3, 5);
    // map.setObstacle(3, 6);
    // map.setObstacle(3, 7);
    // map.setObstacle(3, 1);
    // map.setObstacle(3, 2);
    // map.setObstacle(3, 0);
    // map.setObstacle(3, 9);
    // map.setObstacle(3, 8);
    RandomMap(map, start, goal);

    AStarAlgorithm astar;
    auto path = astar.findPath(map, start, goal);
    MapVisualizer visualizer;
    visualizer.displayMap(map, path, start, goal);

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}