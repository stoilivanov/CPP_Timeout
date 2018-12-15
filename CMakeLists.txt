cmake_minimum_required(VERSION 2.8)

project(TestProject)
include(gtest.cmake)

add_executable(tests tests_main.cpp)

# GTest needs threading support
find_package (Threads)
target_link_libraries(tests gtest ${CMAKE_THREAD_LIBS_INIT})
