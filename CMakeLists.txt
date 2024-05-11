cmake_minimum_required(VERSION 3.27)
project(assignment1)

set(CMAKE_CXX_STANDARD 11)

add_executable(assignment1
        Demo.cpp
        Algorithms.hpp
        Algorithms.cpp
        doctest.h
        Graph.cpp
        Test.cpp
        TestCounter.cpp
)
