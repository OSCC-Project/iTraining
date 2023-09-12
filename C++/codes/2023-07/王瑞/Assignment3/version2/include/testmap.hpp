/**
 * @file testmap.hpp
 * @author wangrui
 * @brief
 * @version 0.1
 * @date 2023-08-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once

#include <vector>

namespace mytestmap {
class TestMap {
public:
  TestMap() = default;
  ~TestMap() {
    _testmap.clear();
    _testmap.shrink_to_fit();
  }
  void set_TestMap(const int rows, const int cols, const double obstacleRatio);
  std::vector<std::vector<int>> get_TestMap() { return _testmap; }

private:
  std::vector<std::vector<int>> _testmap;
};
} // namespace mytestmap