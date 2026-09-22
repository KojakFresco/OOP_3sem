cmake_minimum_required(VERSION 4.3)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(main main.cpp)

add_library(ArrayOps array_ops.cpp)
target_sources(ArrayOps
        PUBLIC
            FILE_SET HEADERS
            FILES array_ops.h
)

target_link_libraries(main
        PRIVATE
        ArrayOps
)

include(FetchContent)
FetchContent_Declare(
        GoogleTest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(GoogleTest)

enable_testing()

add_executable(run_tests array_ops_tests.cpp)
target_link_libraries(run_tests PRIVATE ArrayOps GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)