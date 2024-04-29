cmake_minimum_required(VERSION 3.27)
project(Matrix)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Matrix
        App.cpp
        ExtendedTest.cpp
        Matrix.cpp
        ShortTest.cpp
        MatrixIterator.cpp)
