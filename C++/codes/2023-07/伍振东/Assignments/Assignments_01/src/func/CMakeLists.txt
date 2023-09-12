project(graphfunc)

make_directory(${CMAKE_BINARY_DIR}/lib)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

set(LIB_NAME ${PROJECT_NAME} CACHE STRING "graphfunc" FORCE)
add_library(${LIB_NAME} STATIC Graph.cpp)

include_directories(${ROOT_DIR}/include)