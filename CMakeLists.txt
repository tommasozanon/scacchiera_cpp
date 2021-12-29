cmake_minimum_required(VERSION 3.2)

project(scacchiera_cpp)

add_library(Pawn2
pieces/Pawn2.h
pieces/Pawn2.cpp
)

add_library(Rook
pieces/Rook.h
pieces/Rook.cpp
)

add_library(Bishop
pieces/Bishop.h
pieces/Bishop.cpp
)

add_library(Queen
pieces/Queen.h
pieces/Queen.cpp
)

add_library(Pawn7
pieces/Pawn7.h
pieces/Pawn7.cpp
)

add_library(Knight
pieces/Knight.h
pieces/Knight.cpp
)

add_library(King
pieces/King.h
pieces/King.cpp
)

add_library(Board
Board.h
Board.cpp
)

add_executable(main
main.cpp
)

target_link_libraries(main
Board
Rook
Pawn7
Pawn2
Bishop
Queen
Knight
King
)