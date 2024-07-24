cmake_minimum_required(VERSION 3.10)
project(MyLargeProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
# 添加全局包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)
# 包含子目录
add_subdirectory(src)
add_subdirectory(test)

