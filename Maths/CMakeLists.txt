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

add_executable(prime prime.t.cpp)
target_link_libraries(prime gtest_main)
gtest_discover_tests(prime)

add_executable(phi phi.t.cpp)
target_link_libraries(phi gtest_main)
gtest_discover_tests(phi)

add_executable(fact_lcm fact_lcm.t.cpp)
target_link_libraries(fact_lcm gtest_main)
gtest_discover_tests(fact_lcm)

add_executable(inv inv.t.cpp)
target_link_libraries(inv gtest_main)
gtest_discover_tests(inv)