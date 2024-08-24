cmake_minimum_required(VERSION 3.10)

project(AStar)
# 设置输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
# 链接头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)
# 查找SFML库
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
# 添加子目录
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
# 编译可执行文件
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
# 设置gtest变量
set(GTEST_LIBS ${PROJECT_NAME} libgtest.a libgtest_main.a pthread)
# 链接库
target_link_libraries(${PROJECT_NAME} Astar)
target_link_libraries(${PROJEXT_NAME} ${GTEST_LIBS})
# 资源目录
set(RESOURCE_DIR "${CMAKE_SOURCE_DIR}/resources")
# 将资源文件复制到构建目录
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR}/resources)
