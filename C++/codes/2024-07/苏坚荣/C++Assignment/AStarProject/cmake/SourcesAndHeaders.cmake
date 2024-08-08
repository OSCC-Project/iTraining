set(sources
    src/AStar.cpp
    src/Map.cpp
    src/Node.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/AStarProject/AStar.hpp
    include/AStarProject/Node.hpp
    include/AStarProject/Map.hpp
)

set(test_sources
  src/tmp_test.cpp
)
