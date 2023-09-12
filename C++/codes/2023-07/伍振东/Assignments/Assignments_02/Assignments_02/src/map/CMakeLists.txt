add_library(Map Map.cpp)

target_link_libraries(Map Point)

target_include_directories(Map PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})