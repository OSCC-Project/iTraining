# 声明要求的cmake最低版本
cmake_minimum_required(VERSION 3.15)

# 声明一个cmake工程
project(assignment1)

# 打印相关消息
MESSAGE(STATUS "my first cmake project")

# 设置路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

# 设置头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 编译静态库
add_library(graph STATIC ${PROJECT_SOURCE_DIR}/src/graph.cpp)

# 编译可执行文件
add_executable(${PROJECT_NAME} main.cpp)

# 链接需要的库
target_link_libraries(${PROJECT_NAME} graph)

# gtest
target_link_libraries(${PROJECT_NAME} libgtest.a libgtest_main.a pthread)

# compile_commands.json中包含所有编译单元执行的指令
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 打包功能
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
