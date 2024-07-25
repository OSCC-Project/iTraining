set(sources
    src/Astar.cpp
    src/Map.cpp
    src/Point.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/Astar/Astar.hpp
    include/Astar/Map.hpp
    include/Astar/Point.hpp
)

set(test_sources
  src/tmp_test.cpp
)
