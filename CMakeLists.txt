cmake_minimum_required(VERSION 3.9)
project(list)

set(CMAKE_CXX_STANDARD 11)

add_executable(list list.h list.cpp main.cpp library1.h library1.cpp)