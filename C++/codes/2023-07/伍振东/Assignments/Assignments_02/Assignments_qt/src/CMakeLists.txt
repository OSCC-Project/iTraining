
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(point)
add_subdirectory(map)

add_executable(aStar main.cpp)

# 设置Qt的路径
# set(QT_DIR "usr/lib/qt5")
# set(CMAKE_PREFIX_PATH ${QT_DIR})

# 查找并加载Qt库
# target_link_libraries(aStar Map Point)
# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
target_link_libraries(aStar Map Point)
