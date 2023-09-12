cmake_minimum_required(VERSION 3.0.0)
project(assignment3 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/point)
include_directories(${PROJECT_SOURCE_DIR}/gridmap)

include_directories(${PROJECT_SOURCE_DIR}/astar)
add_subdirectory(${PROJECT_SOURCE_DIR}/astar)
set(EXTRA_LIBS ${EXTRA_LIBS} astar)

add_executable(${PROJECT_NAME} main.cpp)

set(EXTRA_LIBS ${EXTRA_LIBS} libgtest.a libgtest_main.a pthread)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
