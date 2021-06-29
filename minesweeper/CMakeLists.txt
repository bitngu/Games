cmake_minimum_required(VERSION 3.10)
project(minesweeper C)

set(CMAKE_C_STANDARD 11)

add_executable(minesweeper main.c move.c move.h inputValidation.c inputValidation.h win.c win.h board.c board.h)