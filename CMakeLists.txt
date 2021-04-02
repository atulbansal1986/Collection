cmake_minimum_required(VERSION 3.19.4)

project(Collection)

add_subdirectory(Maths)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()

SET(GCC_COMPILE_FLAGS "-Wall -Wextra -pedantic -std=c++2a \
                       -g3 -Wshadow -Wformat=2 -Wfloat-equal \
                       -Wconversion -Wlogical-op -Wcast-qual \
                       -Wcast-align -D_GLIBCXX_DEBUG \
                       -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 \
                       -fsanitize=address -fstack-protector")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COMPILE_FLAGS}")


include(GoogleTest)

add_executable(hello hello.t.cpp)
target_link_libraries(hello gtest_main)
gtest_discover_tests(hello)


