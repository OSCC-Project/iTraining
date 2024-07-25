# tests/CMakeLists.txt
add_executable(test_MyAStar test_MyAStar.cpp)

target_include_directories(test_MyAStar
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/MyAStar
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/MyMap
    ${CMAKE_CURRENT_SOURCE_DIR}/../src/MyPoint
)

target_link_libraries(test_MyAStar
    gtest_main
    astar_lib
    map_lib
    point_lib
    termcolor
)

include(GoogleTest)
gtest_discover_tests(test_MyAStar)
