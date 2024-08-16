# Google Test 配置
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/mrlris/iTraining/C++/codes/2024-07/赵正杰/Astar/bin)
# 添加测试程序
add_executable(test_moduel test_case.cpp)
#target_link_libraries(test_moduel Graph Vis Astar)
target_link_libraries(test_moduel Astar ${GTEST_LIBRARIES} pthread)
