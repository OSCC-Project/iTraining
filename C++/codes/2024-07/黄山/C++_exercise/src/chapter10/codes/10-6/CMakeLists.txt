cmake_minimum_required(VERSION 3.10)
project(10-6)

include_directories(include)

file(GLOB SRC_FILES src/*.cpp)

add_executable(exercise_10_6 ${SRC_FILES})

set_target_properties(exercise_10_6 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH})