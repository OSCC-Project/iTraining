# 设置源文件列表
file(GLOB MODULE1_SRC_FILES Graph.cpp)

# 定义静态库
add_library(Graph STATIC ${MODULE1_SRC_FILES})

# 添加包含目录
target_include_directories(Graph PUBLIC ${PROJECT_SOURCE_DIR}/src/Graph)