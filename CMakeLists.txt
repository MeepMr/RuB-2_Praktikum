cmake_minimum_required(VERSION 3.16)
project(RB2_Praktikum C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_CXX_FLAGS -pthread)
find_package(Threads REQUIRED)
add_executable(RB2_Praktikum RB2_Pr08/Aufgabe2/thread_simple.c)

target_link_libraries(RB2_Praktikum Threads::Threads)