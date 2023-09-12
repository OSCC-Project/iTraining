cmake_minimum_required(VERSION 3.16.3)

project("10-3" VERSION 1.0 LANGUAGES CXX )

include_directories(golf)

add_executable(${PROJECT_NAME} main.cpp golf.cpp)
