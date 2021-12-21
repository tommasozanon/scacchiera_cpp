#include "Board.h"
#include "pieces/Pawn2.h"
#include "pieces/Pawn7.h"
#include <iostream>

Board::Board() {
    short pos[2]{0, 0};
    for (short col = 0; col < 8; col++) {
        pos[0] = 1;
        pos[1] = col;
        board[1][col] = Pawn2(pos);
        pos[0] = 6;
        pos[1] = col;
        board[6][col] = Pawn7(pos);
    }
    board[1][0].to_string();
}

void Board::print() {
    for (short row = 0; row < 8; row++) {
        for (short col = 0; col < 8; col++) {
            board[row][col].to_string();
        }
        std::cout << std::endl;
    }
}