cmake_minimum_required(VERSION 3.15)
project(TestTasks)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    FirstTask
    firstTask.cpp
)

add_executable(
    SecondTask
    secondTask.cpp
    tree.cpp
)