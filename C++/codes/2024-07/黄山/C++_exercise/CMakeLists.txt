cmake_minimum_required(VERSION 3.5.0)
project(cpp_exercise VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB chapters ${PROJECT_SOURCE_DIR}/chapter*)

foreach(subdirs ${chapters})
    add_subdirectory(${subdirs})
endforeach()
