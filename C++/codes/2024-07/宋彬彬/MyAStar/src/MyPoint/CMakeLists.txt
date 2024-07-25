add_library(point_lib "")

target_sources(point_lib
PRIVATE
    MyPoint.cpp
PUBLIC
    MyPoint.hpp
)

target_include_directories(point_lib
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)