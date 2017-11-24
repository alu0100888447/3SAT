cmake_minimum_required(VERSION 3.8)
project(Practica4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Sat3.cpp include/Sat3.h)
add_executable(Practica4 ${SOURCE_FILES})