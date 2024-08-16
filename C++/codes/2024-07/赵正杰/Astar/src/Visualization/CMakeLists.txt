# 设置源文件列表
file(GLOB MODULE1_SRC_FILES Visual.cpp)

# 定义静态库
add_library(Vis STATIC ${MODULE1_SRC_FILES})

# 添加包含目录
target_include_directories(Vis PUBLIC ${PROJECT_SOURCE_DIR}/src/Visualization)

# 链接Graph库
target_link_libraries(Vis PUBLIC Graph)