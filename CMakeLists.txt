cmake_minimum_required(VERSION 3.2)

project(scacchiera_cpp)

add_library(Pawn1
pieces/Pawn1.h
pieces/Pawn1.cpp
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

add_library(Pawn6
pieces/Pawn6.h
pieces/Pawn6.cpp
)

add_library(Knight
pieces/Knight.h
pieces/Knight.cpp
)

add_library(King
pieces/King.h
pieces/King.cpp
)

add_library(Space
pieces/Space.h
pieces/Space.cpp
)


add_library(Board
Board.h
Board.cpp
)

add_library(get_moves
get_moves.h
get_moves.cpp
)

add_library(special_moves
special_moves.h
special_moves.cpp
)

add_library(draw
draw.h
draw.cpp
)

add_executable(main
main.cpp
)

add_executable(scacchiera
scacchiera.cpp
)

add_executable(replay
replay.cpp
)

target_link_libraries(main
Board
Rook
Pawn6
Pawn1
Bishop
Queen
Knight
King
Space
get_moves
special_moves
draw
)

target_link_libraries(scacchiera
Board
Rook
Pawn6
Pawn1
Bishop
Queen
Knight
King
Space
get_moves
special_moves
draw
)

target_link_libraries(replay
Board
Rook
Pawn6
Pawn1
Bishop
Queen
Knight
King
Space
)