#include <gtest/gtest.h>

#include "project/obstacle_map.hpp"

// TEST(TmpAddTest, CheckValues)
// {
//   ASSERT_EQ(tmp::add(1, 2), 3);
//   EXPECT_TRUE(true);
// }

TEST(PathFindTest, StandardMap)
{
  EXPECT_TRUE(main_path_finding());
}

TEST(PathFindTest, RandomMap)
{
  EXPECT_TRUE(main_path_finding(false));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
