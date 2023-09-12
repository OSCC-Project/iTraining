#include <iostream>
#include <random>
#include <vector>

#include "MyAstar/MyAstar.hpp"

using namespace Assignment2;

int main()
{
  bool flag = 0;
  const int n = 5;
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
  std::vector<std::vector<int>> themap = {
    { 0, 0, 0, 0, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0, 1, 1, 1 }, { 1, 1, 0, 1, 1, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }
  };

  AStar mymap(themap);
  flag = mymap.startAStar(&mymap[0][0], &mymap[3][7]);
  std::string output = mymap.set_Path(flag, &mymap[3][7]);
  std::cout << output << std::endl;

  // test
  for (int i = 0; i < n; ++i)
  {
    TestMap thetestmap;
    thetestmap.set_TestMap(rowcol[i][0], rowcol[i][1], obstacleRatio[i]);
    AStar testmap(thetestmap.get_TestMap());
    flag = testmap.startAStar(&testmap[0][0], &testmap[rowcol[i][0] - 1][rowcol[i][1]] - 1);
    std::string output = testmap.set_Path(flag, &testmap[rowcol[i][0] - 1][rowcol[i][1] - 1]);
    testmap.showMap();
    std::cout << output << std::endl;
  }

  return 0;
}