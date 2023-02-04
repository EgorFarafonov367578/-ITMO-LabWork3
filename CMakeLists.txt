cmake_minimum_required(VERSION 3.20)
project(Third_lab_jb)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Third_lab_jb main.cpp
        BMPlib/BMPwriting.cpp
        BMPlib/BMPwriting.h
        Core/SandModel.h
        Core/SandModel.cpp)