cmake_minimum_required(VERSION 3.26)
project(Exam_2023_OOP)

set(CMAKE_CXX_STANDARD 20)

option(SANITIZERS OFF)
if(SANITIZERS)
    # (just for debugging, needs WSL)
    set(CMAKE_CXX_FLAGS -fsanitize=address,undefined,leak)
endif()

add_executable(Exam_2023_OOP main.cpp)
