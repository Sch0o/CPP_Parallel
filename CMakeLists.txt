cmake_minimum_required(VERSION 3.28)
project(CPP_Parallel)

set(CMAKE_CXX_STANDARD 17)

add_executable(CPP_Parallel main.cpp)

add_executable(demo1 call_from.cpp)

add_executable(demo2 lock_basics.cpp)