
cmake_minimum_required(VERSION 3.0.0)
project(Astar)

# 包含头文件目录
include_directories(include/project)

# 搜索源文件和头文件
file(GLOB MAIN_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB MAIN_HEAD ${CMAKE_CURRENT_SOURCE_DIR}/include/project/*.h)

# 创建一个静态库，将所有源文件添加到库中
add_library(MyProjectLib STATIC ${MAIN_SRC})

# 添加可执行文件
add_executable(MyProject ${MAIN_SRC})

# 链接库到可执行文件
target_link_libraries(MyProject MyProjectLib)

# 启用测试
enable_testing()

# 查找 GoogleTest 库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 包含测试目录
add_subdirectory(test)

# 查找 Doxygen 包
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # 设置 Doxygen 输入和输出文件
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # 请求重新配置 Doxyfile
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    # 添加一个自定义目标来运行 Doxygen，每当项目构建时
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
