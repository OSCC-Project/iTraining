cmake_minimum_required(VERSION 3.0.0)

project("9-1" VERSION 1.0 LANGUAGES CXX )

include_directories(golf)

add_executable(${PROJECT_NAME} main.cpp golf.cpp)
