cmake_minimum_required(VERSION 3.17)
project(CSVO)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-lncurses")


include_directories(.)

add_executable(CSVO
        CSGO.h
        main.cpp
        )
