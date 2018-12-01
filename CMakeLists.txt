cmake_minimum_required(VERSION 3.10)
project(list)

set(CMAKE_CXX_STANDARD 11)

add_executable(list lib_main.cpp list.h list.cpp  library1.h library1.cpp)