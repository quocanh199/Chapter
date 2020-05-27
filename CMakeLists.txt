cmake_minimum_required(VERSION 3.15)
project(Chapter1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chapter1
        Date.cpp
        Date.h
        Main.cpp
        Menu.cpp
        Menu.h
        SinhVien.cpp
        SinhVien.h Searching.h Searching.cpp Statistic.h Statistic.cpp)
