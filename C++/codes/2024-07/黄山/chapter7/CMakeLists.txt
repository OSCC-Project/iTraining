PROJECT(exercises_7_10)
SET(SRC_LIST src/7-10.cpp)
ADD_EXECUTABLE(exercise_7_10 ${SRC_LIST})

set_target_properties(exercise_7_10 PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
