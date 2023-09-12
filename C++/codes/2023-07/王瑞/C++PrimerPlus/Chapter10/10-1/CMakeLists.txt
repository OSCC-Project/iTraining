cmake_minimum_required(VERSION 3.16.3)

project("10-1" VERSION 1.0 LANGUAGES CXX )

include_directories(bank)

add_executable(${PROJECT_NAME} main.cpp bank.cpp)
