cmake_minimum_required(VERSION 3.14)
project(rng)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2")

add_executable(${PROJECT_NAME} main.cpp)
