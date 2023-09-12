/**
 * @file main.cpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-07-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "dag.h"
#include <iostream>

int main() {
  const int edges_num = 8;
  int vertices_num = 6;
  int start, end;
  AnsPath anspath;
  Path tmp_path;

  Path mid_point;

  int dag_map[edges_num][3] = {
      {0, 1, 5}, {0, 2, 5}, {0, 3, 4}, {1, 3, 1},
      {2, 4, 7}, {3, 4, 2}, {3, 5, 8}, {4, 5, 1},
  };

  Map my_map(edges_num, dag_map);

  start = 0;
  end = 5;
  int topN = 3;
  Edge edge(start, end, 0);
  my_map.addMapEdge();

  mid_point.addPathVertex(3);
  mid_point.addPathVertex(4);

  my_map.DFS(edge, vertices_num, anspath, tmp_path, mid_point);
  anspath.dessortAnspath();
  anspath.showAnsPath(topN);

  return 0;
}