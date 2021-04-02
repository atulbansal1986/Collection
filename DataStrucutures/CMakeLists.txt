include(GoogleTest)
enable_testing()

add_executable(DSU DSU.t.cpp)
target_link_libraries(DSU gtest_main)
gtest_discover_tests(DSU)