add_library(map_lib "")

target_sources(map_lib
PRIVATE
    MyMap.cpp
PUBLIC
    MyMap.hpp
)

target_include_directories(map_lib
PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)