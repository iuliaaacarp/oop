cmake_minimum_required(VERSION 3.28)
project(test_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(test_1 main.cpp
        Weather.h
        Weather.cpp
        DynamicArray.h
        Service.h
        DynamicArray.cpp
        Service.cpp
        UI.h
        UI.cpp)
