cmake_minimum_required(VERSION 3.20)
project(Calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Calculator main.cpp Stack.h Type.cpp Type.h StringTokenizer.cpp StringTokenizer.h PolishNotation.cpp PolishNotation.h Calculator.cpp Calculator.h)

project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run tests.cpp Calculator.h Stack.h Type.cpp Type.h StringTokenizer.cpp StringTokenizer.h PolishNotation.cpp PolishNotation.h Calculator.cpp Calculator.h)
target_link_libraries(Google_Tests_run gtest gtest_main)