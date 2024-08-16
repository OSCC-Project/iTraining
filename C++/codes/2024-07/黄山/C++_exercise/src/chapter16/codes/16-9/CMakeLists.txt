cmake_minimum_required(VERSION 3.10)
project(16-9)

include_directories(include)

# 顺序不对会导致依赖问题
# file(GLOB SRC_FILES src/*.cpp)

add_executable(exercise_16_9 src/main.cpp)

set_target_properties(exercise_16_9 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH})