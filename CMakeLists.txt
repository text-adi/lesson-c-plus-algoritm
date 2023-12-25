cmake_minimum_required(VERSION 3.27)
project(lesson_c_plus_algoritm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(l4)

add_executable(lesson_c_plus_algoritm
        l4/main.cpp)
