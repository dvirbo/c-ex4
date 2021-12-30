cmake_minimum_required(VERSION 3.21)
project(c_ex4 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(c_ex4
        algo.c
        algo.h
        main.c
        vertex.c
        vertex.h
        graph.c
        graph.h)
