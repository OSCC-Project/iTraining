# external/CMakeLists.txt
add_library(termcolor INTERFACE)
add_subdirectory(googletest)

# 指定包含目录
target_include_directories(termcolor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
