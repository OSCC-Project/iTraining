cmake_minimum_required(VERSION 3.10)
project(12-4)

include_directories(include)

# 顺序不对会导致依赖问题
# file(GLOB SRC_FILES src/*.cpp)

add_executable(exercise_12_4 src/stack.cpp src/main.cpp)

set_target_properties(exercise_12_4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH})