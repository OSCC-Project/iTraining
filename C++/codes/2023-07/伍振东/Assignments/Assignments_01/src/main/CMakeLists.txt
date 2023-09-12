project(Main)

add_executable(Assignments_01 main.cpp)

target_link_libraries(Assignments_01 ${LIB_NAME})

include_directories(${ROOT_DIR}/include)

make_directory(${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
