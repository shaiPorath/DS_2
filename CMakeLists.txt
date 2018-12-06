cmake_minimum_required(VERSION 3.9)
project(list)

set(CMAKE_CXX_STANDARD 11)

add_executable(list part2_main.cpp ImageTagger.cpp ImageTagger.h tree.h
        tree.cpp list.h list.cpp library2.cpp library2.h)