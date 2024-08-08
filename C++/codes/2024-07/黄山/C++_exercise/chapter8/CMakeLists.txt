cmake_minimum_required(VERSION 3.10)
project(chapter8)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)

file(MAKE_DIRECTORY ${BINARY_DIR})

file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(FILENAME ${SOURCE_FILE} NAME_WE)
    
    add_executable("exercise_${FILENAME}" ${SOURCE_FILE})

    set_target_properties("exercise_${FILENAME}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BINARY_DIR}
    )
endforeach()
