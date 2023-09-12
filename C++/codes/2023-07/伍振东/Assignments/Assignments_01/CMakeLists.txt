cmake_minimum_required(VERSION 3.16.0)
project(Assignments_01)
message(${CMAKE_SOURCE_DIR})
set(ROOT_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src/func)
add_subdirectory(src/main)