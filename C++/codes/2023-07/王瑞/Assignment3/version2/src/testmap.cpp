#include "testmap.hpp"
#include <random>

namespace mytestmap {
void TestMap::set_TestMap(const int rows, const int cols,
                          const double obstacleRatio) {
  _testmap.resize(rows, std::vector<int>(cols));
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      double randomNum = dis(gen);
      int value = (randomNum < obstacleRatio) ? 1 : 0;
      _testmap[i][j] = value;
    }
  }
  _testmap[rows - 1][cols - 1] = 0;
  _testmap[0][0] = 0;
}
} // namespace mytestmap	
