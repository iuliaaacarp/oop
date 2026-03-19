cmake_minimum_required(VERSION 3.28)
project(seminar2)

set(CMAKE_CXX_STANDARD 20)

add_executable(seminar2 main.cpp
        song.h
        song.cpp
        DynamicArray.cpp
        DynamicArray.h
        Repository.cpp
        Repository.h)
