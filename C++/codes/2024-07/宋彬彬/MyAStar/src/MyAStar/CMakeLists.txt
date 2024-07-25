add_library(astar_lib "")

target_sources(astar_lib
PRIVATE
    MyAStar.cpp
PUBLIC
    MyAStar.hpp
)

target_include_directories(astar_lib
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)