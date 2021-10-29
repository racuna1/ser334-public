cmake_minimum_required(VERSION 3.20)
project(M07_MutexBasics C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(M07_MutexBasics main.c)
