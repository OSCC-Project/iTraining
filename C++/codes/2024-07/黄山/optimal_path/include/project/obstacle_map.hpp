#pragma once

#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

const int WIDTH = 25;         // map边长
const int STRINGLENGTH = 50;  // 每行string长度(25 + 24 + 1)
const int directions[3][8] = { { -1, -1, 0, 1, 1, 1, 0, -1 },
                               { 0, -1, -1, -1, 0, 1, 1, 1 },
                               { 10, 14, 10, 14, 10, 14, 10, 14 } };  // 周围八个方向及cost

class obstacleMap
{
 public:
  struct Node
  {
    int _row;
    int _col;
    int G_value;
    int H_value;
    int F_value;
    bool isPath;   // is in path
    bool isOpen;   // is in open_list
    bool isBlock;  // is in block
    Node* fatherNode;

    Node()
        : _row(0),
          _col(0),
          G_value(INT32_MAX),
          H_value(INT32_MAX),
          F_value(INT32_MAX),
          isPath(false),
          isOpen(false),
          isBlock(false),
          fatherNode(nullptr)
    {
    }
    Node(int row, int col, int h, bool isb)
        : _row(row),
          _col(col),
          G_value(INT32_MAX),
          H_value(h),
          F_value(INT32_MAX),
          isPath(false),
          isOpen(false),
          isBlock(isb),
          fatherNode(nullptr)
    {
    }
    Node(int row, int col, int g, int h, int f, bool isp, bool iso, bool isb, Node* fnode)
        : _row(row),
          _col(col),
          G_value(g),
          H_value(h),
          F_value(f),
          isPath(isp),
          isOpen(iso),
          isBlock(isb),
          fatherNode(fnode)
    {
    }
  };

  using nodeMap = std::vector<std::vector<Node>>;
  using strMap = std::vector<std::string>;

  obstacleMap(bool israndom = false);
  obstacleMap(const strMap& input);
  ~obstacleMap();
  // void mapReconstruct(const strMap& input);
  void toStringMap(strMap& string_map);
  bool pathFinding();
  void pathAnnotation();
  void neighbourSearch(Node* tmpNodePtr, Node* nodePtr, int cost);

 private:
  nodeMap _map;
  std::priority_queue<Node*, std::vector<Node*>, std::function<bool(Node*, Node*)>> _open_list;  //(row, col)
  std::unordered_set<Node*> _closed_list;
  bool _isAccessible;
};

bool isSame(obstacleMap::strMap const& s1, obstacleMap::strMap const& s2);

bool main_path_finding(bool isCase = true);

void showStrMap(const obstacleMap::strMap& map);

bool test_case(const obstacleMap::strMap& originMap, const obstacleMap::strMap& referenceMap);

void readCases(
    const std::string& originPath,
    const std::string& refPath,
    obstacleMap::strMap& originMap,
    obstacleMap::strMap& refMap);