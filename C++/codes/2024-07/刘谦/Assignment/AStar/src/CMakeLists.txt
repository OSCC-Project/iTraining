add_library(Astar  GridMap.cpp AStarAlgorithm.cpp RandomMap.cpp MapVisualizer.cpp)
# 链接 SFML 库
target_link_libraries(Astar sfml-graphics sfml-window sfml-system )
