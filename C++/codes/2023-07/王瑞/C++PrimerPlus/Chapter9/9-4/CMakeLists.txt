cmake_minimum_required(VERSION 3.16.3)

project("9-4" VERSION 1.0 LANGUAGES CXX )

include_directories(sales)

add_executable(${PROJECT_NAME} main.cpp sales.cpp)
