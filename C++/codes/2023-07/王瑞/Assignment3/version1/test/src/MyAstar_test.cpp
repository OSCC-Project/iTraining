#include "MyAstar/MyAstar.hpp"

#include <gtest/gtest.h>

TEST(MyAstar, CheckPath)
{
  bool flag = 0;
  std::vector<std::vector<int>> tmp_map = {
    { 0, 0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 1, 1, 1 }, { 1, 1, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }
  };
  Assignment2::AStar my_map(tmp_map);
  flag = my_map.startAStar(&my_map[0][0], &my_map[3][7]);
  std::vector<Assignment2::Point *> path = my_map.set_Path(flag, &my_map[3][7]);
  std::vector<Assignment2::Point *> result;
  result.push_back(&my_map[3][7]);
  result.push_back(&my_map[3][6]);
  result.push_back(&my_map[2][5]);
  result.push_back(&my_map[1][4]);
  result.push_back(&my_map[1][3]);
  result.push_back(&my_map[1][2]);
  result.push_back(&my_map[1][1]);
  result.push_back(&my_map[0][0]);
  EXPECT_EQ(flag, true);
  EXPECT_EQ(path, result);
}

TEST(MyAstar, CheckValues)
{
  std::vector<std::vector<int>> tmp_map = {
    { 0, 0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 1, 1, 1 }, { 1, 1, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }
  };
  Assignment2::AStar my_map(tmp_map);
  my_map.startAStar(&my_map[0][0], &my_map[3][7]);
  EXPECT_EQ(my_map[1][1].get_G(), 14);
  EXPECT_EQ(my_map[1][1].get_H(), 88);
  EXPECT_EQ(my_map[1][1].get_F(), 102);
  EXPECT_EQ(my_map[2][6].get_H(), 19);
  EXPECT_EQ(my_map[3][6].get_G(), 72);
  EXPECT_NE(my_map[3][6].get_G(), 100);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  bool flag = 0;
  const int n = 3;
  std::random_device rd;
  std::default_random_engine eng(rd());
  //行列生成
  int iminVal = 10;
  int imaxVal = 20;
  int rowcol[n][2];
  std::uniform_int_distribution<int> idist(iminVal, imaxVal);
  for (int i = 0; i < n * 2; ++i)
  {
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
  for (int i = 0; i < n; ++i)
  {
    double value = ddist(eng);
    obstacleRatio[i] = value;
  }

  std::vector<std::vector<int>> tmp_map = {
    { 0, 0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 1, 1, 1 }, { 1, 1, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }
  };
  std::cout << std::endl;
  Assignment2::AStar my_map(tmp_map);
  flag = my_map.startAStar(&my_map[0][0], &my_map[3][7]);
  std::vector<Assignment2::Point *> path = my_map.set_Path(flag, &my_map[3][7]);
  my_map.show_Path(flag, path);
  my_map.get_cost(&my_map[3][7]);
  my_map.showMap();
  for (int i = 0; i < n; ++i)
  {
    std::cout << std::endl;
    Assignment2::TestMap tmp_test_map;
    tmp_test_map.set_TestMap(rowcol[i][0], rowcol[i][1], obstacleRatio[i]);
    Assignment2::AStar test_map(tmp_test_map.get_TestMap());
    flag = test_map.startAStar(&test_map[0][0], &test_map[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    std::vector<Assignment2::Point *> path = test_map.set_Path(flag, &test_map[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    std::cout << "The map is " << rowcol[i][0] << " x " << rowcol[i][1] << std::endl;
    std::cout << "The obstacle ratio is " << obstacleRatio[i] << std::endl;
    test_map.show_Path(flag, path);
    test_map.get_cost(&test_map[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    test_map.showMap();
  }
  return RUN_ALL_TESTS();
}
