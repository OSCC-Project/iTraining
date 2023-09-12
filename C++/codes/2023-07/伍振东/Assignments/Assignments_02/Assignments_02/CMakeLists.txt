cmake_minimum_required(VERSION 3.16.0)
# 设置项目名称
project(aStar)

# 设置可执行文件的输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/lib)

# 添加子目录
add_subdirectory(src)
