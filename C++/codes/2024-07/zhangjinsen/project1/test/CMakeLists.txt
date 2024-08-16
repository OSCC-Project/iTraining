# 添加可执行的测试文件
file(GLOB TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

# 添加 GoogleTest
add_executable(runTests ${TEST_SRC})

# 链接 GoogleTest 和项目的静态库
target_link_libraries(runTests ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES})
target_link_libraries(runTests MyProjectLib)

# 添加测试
add_test(NAME runTests COMMAND runTests)
