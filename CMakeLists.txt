cmake_minimum_required(VERSION 4.0)
project(tic_tac_toe C)

set(CMAKE_C_STANDARD 23)

add_executable(tic_tac_toe main.c
        src/board.h
        src/board.c
        src/search.h
        src/search.c)
