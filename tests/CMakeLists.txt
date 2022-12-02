cmake_minimum_required(VERSION 3.1)
add_executable(Test tests.cpp)
target_link_libraries(Test PUBLIC GTest::gtest_main MainLib)

include(GoogleTest)
gtest_discover_tests(Test)
