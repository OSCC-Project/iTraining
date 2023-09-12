add_library(Map Map.cpp)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

target_link_libraries(Map Qt5::Widgets Point)

target_include_directories(Map PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})