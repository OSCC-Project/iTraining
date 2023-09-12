# 添加源文件
add_library(Point STATIC Point.cpp)

# 添加头文件目录
target_include_directories(Point PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})