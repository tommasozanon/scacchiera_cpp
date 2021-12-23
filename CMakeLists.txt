cmake_minimum_required(VERSION 3.2)

project(scacchiera_cpp)

add_library(Pawn2
pieces/Pawn2.h
pieces/Pawn2.cpp
)

add_library(Pawn7
pieces/Pawn7.h
pieces/Pawn7.cpp
)

add_library(Board
Board.h
Board.cpp
)

add_executable(Main
main.cpp
)
