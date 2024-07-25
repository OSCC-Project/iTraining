cmake_minimum_required(VERSION 3.10) 
project(chapter12)

file(GLOB children ${PROJECT_SOURCE_DIR}/codes/*)

foreach(subdirs ${children})
    add_subdirectory(${subdirs})
endforeach()
