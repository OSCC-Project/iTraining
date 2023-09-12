add_subdirectory(point)
add_subdirectory(map)

add_executable(aStar main.cpp)

target_link_libraries(aStar Map Point)
