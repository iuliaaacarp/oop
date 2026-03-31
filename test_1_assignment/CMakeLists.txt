cmake_minimum_required(VERSION 3.28)
project(test_1_assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_1_assignment main.cpp
        DynamicArray.h
        DynamicArray.cpp
        Assignment.h
        Assignment.cpp
        Service.h
        Service.cpp
        UI.cpp)
