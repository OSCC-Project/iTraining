cmake_minimum_required(VERSION 3.10)
project(chapter8)

set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

file(GLOB SOURCES "${SOURCE_DIR}/*.cpp")

foreach(SOURCE_FILE ${SOURCES})
    get_filename_component(FILENAME ${SOURCE_FILE} NAME_WE)
    
    add_executable("exercise_${FILENAME}" ${SOURCE_FILE})

    set_target_properties("exercise_${FILENAME}" PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${BINARY_OUTPUT_PATH}
    )
endforeach()
