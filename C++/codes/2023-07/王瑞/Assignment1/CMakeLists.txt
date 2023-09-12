cmake_minimum_required(VERSION 3.0.0)

# set the project name
project("Assignment1" VERSION 1.0 LANGUAGES CXX)

include_directories(./include)

# add the executable
add_executable(${PROJECT_NAME} main.cpp ./src/dag.cpp)

