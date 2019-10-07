cmake_minimum_required(VERSION 3.15)
project(glitched)

set(CMAKE_CXX_STANDARD 17)

add_executable(glitched
        main.cpp
        constants.h
        AudioFile.cpp
        AudioFile.h
        )