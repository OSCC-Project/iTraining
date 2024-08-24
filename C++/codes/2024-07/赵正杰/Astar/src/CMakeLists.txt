#包含子目录
add_subdirectory(Graph)
add_subdirectory(Visualization)
add_subdirectory(Algorithm)
# 包含子目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY /home/mrlris/iTraining/C++/codes/2024-07/赵正杰/Astar/bin)
# 设置源文件列表
file(GLOB SRC_FILES main.cpp)#这个函数是用来进行正则匹配那种寻找的

# 定义可执行文件
add_executable(Astar_bin ${SRC_FILES})

# 链接子模块库
target_link_libraries(Astar_bin Graph Vis Astar)