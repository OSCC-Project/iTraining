cmake_minimum_required(VERSION 3.16.3)

project("cmaketest" VERSION 1.0 LANGUAGES CXX )

include_directories(./)

aux_source_directory(./ CPP_LIST)

add_executable(${PROJECT_NAME} ${CPP_LIST})
