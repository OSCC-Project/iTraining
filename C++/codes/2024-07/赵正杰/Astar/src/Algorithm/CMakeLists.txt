# 设置源文件列表
file(GLOB MODULE1_SRC_FILES Astar.cpp)

# 定义静态库
add_library(Astar STATIC ${MODULE1_SRC_FILES})

# 添加包含目录
target_include_directories(Astar PUBLIC ${PROJECT_SOURCE_DIR}/src/Algorithm)

# 链接Graph库
target_link_libraries(Astar PUBLIC Graph)
# 链接Graph库
target_link_libraries(Astar PUBLIC Vis)