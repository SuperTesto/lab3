cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 14)

project(Lab3)
add_executable(main main.cpp)
add_library(StackLib STATIC Stack.cpp Stack.h)
add_library(QueueLib STATIC Queue.cpp Queue.h)

target_link_libraries(main StackLib QueueLib)
