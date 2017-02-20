cmake_minimum_required(VERSION 3.6)
project(circuit)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(circuit ${SOURCE_FILES} main.cpp)