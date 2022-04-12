cmake_minimum_required(VERSION 3.23)
project(LinkedList)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedList main.cpp List.h)
add_executable(Gtest_run list_utest.cpp)

set(Gtest_PATH $ENV{Libraries}\\gtest)
add_subdirectory(${Gtest_PATH} gtest_build)
target_include_directories(Gtest_run PRIVATE ${gtest_SOURCE_DIR}/include)
target_include_directories(Gtest_run PRIVATE ${gtest_SOURCE_DIR})
target_link_libraries(Gtest_run PRIVATE gtest gtest_main)

