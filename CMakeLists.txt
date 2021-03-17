cmake_minimum_required(VERSION 3.17)
project(sudoku_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(sudoku_solver main.cpp table_io.h table_io.cpp solver.h solver.cpp)