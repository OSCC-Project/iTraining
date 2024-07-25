cmake_minimum_required(VERSION 3.10) 
project(chapter10)

set(BINARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB children ${PROJECT_SOURCE_DIR}/codes/*)

foreach(subdirs ${children})
    add_subdirectory(${subdirs})
endforeach()
