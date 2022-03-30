cmake_minimum_required(VERSION 3.21)
project(p03 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(p03
        ironpuzzle.c
        png.h
        pngfileio.c)
