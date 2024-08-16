set(sources
    # src/tmp.cpp
    src/obstacle_map.cpp
    src/test_functions.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    # include/project/tmp.hpp
    include/project/obstacle_map.hpp
)

set(test_sources
  src/tmp_test.cpp
)
