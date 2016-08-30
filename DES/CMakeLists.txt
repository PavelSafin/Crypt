cmake_minimum_required(VERSION 3.5.1)
project(DES)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES DES.cpp main.cpp)
set(HEADER DES.h)
add_executable(DES ${SOURCE_FILES})