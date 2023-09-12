#include "astar.hpp"
#include "point.hpp"
#include "testmap.hpp"
#include <random>

#include <gtest/gtest.h>

TEST(MyAstar, CheckPath) {
  bool flag = 0;
  std::vector<std::vector<int>> themap = {{0, 0, 0, 0, 1, 1, 1, 1},
                                          {0, 0, 0, 0, 0, 1, 1, 1},
                                          {1, 1, 0, 1, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 0}};
  myastar::AStar mymap(themap);
  flag = mymap.startAStar(&mymap[0][0], &mymap[3][7]);
  std::vector<mypoint::Point *> path = mymap.set_Path(flag, &mymap[3][7]);
  std::vector<mypoint::Point *> result;
  result.push_back(&mymap[3][7]);
  result.push_back(&mymap[3][6]);
  result.push_back(&mymap[2][5]);
  result.push_back(&mymap[1][4]);
  result.push_back(&mymap[1][3]);
  result.push_back(&mymap[1][2]);
  result.push_back(&mymap[1][1]);
  result.push_back(&mymap[0][0]);
  EXPECT_EQ(flag, true);
  EXPECT_EQ(path, result);
}

TEST(MyAstar, CheckValues) {
  std::vector<std::vector<int>> themap = {{0, 0, 0, 0, 1, 1, 1, 1},
                                          {0, 0, 0, 0, 0, 1, 1, 1},
                                          {1, 1, 0, 1, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 0}};
  myastar::AStar mymap(themap);
  mymap.startAStar(&mymap[0][0], &mymap[3][7]);
  EXPECT_EQ(mymap[1][1].get_G(), 14);
  EXPECT_EQ(mymap[1][1].get_H(), 88);
  EXPECT_EQ(mymap[1][1].get_F(), 102);
  EXPECT_EQ(mymap[2][6].get_H(), 19);
  EXPECT_EQ(mymap[3][6].get_G(), 72);
  EXPECT_NE(mymap[3][6].get_G(), 100);
}

int main(int argc, char **argv) {

  bool flag = 0;
  const int n = 3;
  std::random_device rd;
  std::default_random_engine eng(rd());
  //行列生成
  int iminVal = 10;
  int imaxVal = 20;
  int rowcol[n][2];
  std::uniform_int_distribution<int> idist(iminVal, imaxVal);
  for (int i = 0; i < n * 2; ++i) {
    int row = i / 2;
    int col = i % 2;
    int value = idist(eng);
    rowcol[row][col] = value;
  }
  //难度生成
  double dminVal = 0.1;
  double dmaxVal = 0.6;
  std::vector<double> obstacleRatio(n);
  std::uniform_real_distribution<double> ddist(dminVal, dmaxVal);
  for (int i = 0; i < n; ++i) {
    double value = ddist(eng);
    obstacleRatio[i] = value;
  }

  std::vector<std::vector<int>> themap = {{0, 0, 0, 0, 1, 1, 1, 1},
                                          {0, 0, 0, 0, 0, 1, 1, 1},
                                          {1, 1, 0, 1, 1, 0, 0, 0},
                                          {0, 0, 0, 0, 0, 0, 0, 0}};
  std::cout << std::endl;
  myastar::AStar mymap(themap);
  flag = mymap.startAStar(&mymap[0][0], &mymap[3][7]);
  std::vector<mypoint::Point *> path = mymap.set_Path(flag, &mymap[3][7]);
  mymap.show_Path(flag, path);
  mymap.get_cost(&mymap[3][7]);
  mymap.showMap();
  for (int i = 0; i < n; ++i) {
    std::cout << std::endl;
    mytestmap::TestMap thetestmap;
    thetestmap.set_TestMap(rowcol[i][0], rowcol[i][1], obstacleRatio[i]);
    myastar::AStar testmap(thetestmap.get_TestMap());
    flag = testmap.startAStar(&testmap[0][0],
                              &testmap[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    std::vector<mypoint::Point *> path =
        testmap.set_Path(flag, &testmap[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    std::cout << "The map is " << rowcol[i][0] << " x " << rowcol[i][1]
              << std::endl;
    std::cout << "The obstacle ratio is " << obstacleRatio[i] << std::endl;
    testmap.show_Path(flag, path);
    testmap.get_cost(&testmap[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    testmap.showMap();
  }
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
