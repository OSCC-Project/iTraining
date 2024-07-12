cmake_minimum_required(VERSION 3.0)
project(Chapter7)

# 定义所有的源文件
set(SOURCES
    7_1.cpp
    7_2.cpp
    7_3.cpp
    7_4.cpp
    7_5.cpp
    7_6.cpp
    7_7.cpp
    7_8.cpp
    7_9.cpp
)

# 为每个源文件生成一个可执行文件
foreach(SOURCE ${SOURCES})
    get_filename_component(EXE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXE_NAME} ${SOURCE})
endforeach()
