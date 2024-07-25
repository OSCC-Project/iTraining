add_executable(main main.cpp)

add_subdirectory(MyAStar)
add_subdirectory(MyMap)
add_subdirectory(MyPoint)

target_include_directories(main
PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/MyAStar
    ${CMAKE_CURRENT_SOURCE_DIR}/MyMap
    ${CMAKE_CURRENT_SOURCE_DIR}/MyPoint
)

target_link_libraries(main
PRIVATE
    astar_lib
    map_lib
    point_lib
    termcolor
)