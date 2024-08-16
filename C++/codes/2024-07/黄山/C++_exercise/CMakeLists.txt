cmake_minimum_required(VERSION 3.5.0)
project(cpp_exercise VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB chapters ${PROJECT_SOURCE_DIR}/src/chapter*)

set(BINARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

foreach(subdirs ${chapters})
    add_subdirectory(${subdirs})
endforeach()
