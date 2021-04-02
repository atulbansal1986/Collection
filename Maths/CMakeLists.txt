include(GoogleTest)
enable_testing()

add_executable(fib fib.t.cpp)
target_link_libraries(fib gtest_main)
gtest_discover_tests(fib)


add_executable(gcd gcd.t.cpp)
target_link_libraries(gcd gtest_main)
gtest_discover_tests(gcd)

add_executable(pow pow.t.cpp)
target_link_libraries(pow gtest_main)
gtest_discover_tests(pow)