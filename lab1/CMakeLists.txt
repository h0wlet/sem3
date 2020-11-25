cmake_minimum_required(VERSION 3.17)
project(lab)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab main.cpp catch.hpp catch.cpp LinkedList.cpp LinkedList.h iterator.cpp const_iterator.cpp)
