cmake_minimum_required(VERSION 3.10)
project(9-4)

include_directories(include)

file(GLOB SRC_FILES src/*.cpp)

add_executable(exercise_9_4 ${SRC_FILES})

set_target_properties(exercise_9_4 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH})