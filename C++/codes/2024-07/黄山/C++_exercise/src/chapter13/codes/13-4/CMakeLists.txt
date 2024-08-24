cmake_minimum_required(VERSION 3.10)
project(13-4)

include_directories(include)

# 顺序不对会导致依赖问题
# file(GLOB SRC_FILES src/*.cpp)

add_executable(exercise_13_4 src/port.cpp src/vintageport.cpp src/main.cpp)

set_target_properties(exercise_13_4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH})