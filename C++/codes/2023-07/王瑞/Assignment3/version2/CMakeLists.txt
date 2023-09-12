cmake_minimum_required(VERSION 3.0.0)

project(Assignment3 VERSION 0.2.0 LANGUAGES CXX)
# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
# 链接头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
# 添加子目录
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
# 编译可执行文件
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/test/MyAstar_test.cpp)
# 设置gtest变量
set(GTEST_LIBS ${PROJECT_NAME} libgtest.a libgtest_main.a pthread)
# 链接库
target_link_libraries(${PROJECT_NAME} MyAstar)
target_link_libraries(${PROJEXT_NAME} ${GTEST_LIBS})