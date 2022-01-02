#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn2.h"
#include "pieces/Pawn7.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "pieces/Space.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

char names_white[]{'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T', 'P'};
char names_black[]{'t', 'c', 'a', 'd', 'r', 'a', 'c', 't', 'p'};

Board::Board() {
    std::shared_ptr<Piece> p;
    for (short x = 0; x < 8; x++) {
        board.push_back(std::vector<std::shared_ptr<Piece>>());
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            board[x].push_back(std::shared_ptr<Piece>(new Space(pos, ' ')));
        }
    }

    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0) {
        Board::initialize_board(0, 7);
    } else {
        Board::initialize_board(7, 0);
    }
}

void Board::print() {
    short row_n = 1;
    for (short row = 7; row >= 0; row--) {
        std::cout << row_n++ << " ";
        for (short col = 7; col >= 0; col--) {
            if (board[row][col] != nullptr)
                std::cout << board[row][col]->to_char() << "|";
        }
        std::cout << std::endl;
        std::cout << "  ";

        for (short i = 0; i < 16; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (short i = 97; i <= 104; i++) {
        std::cout << (char)i << " ";
    }
    std::cout << std::endl;
}

void Board::initialize_board(int white_n, int black_n) {
    short x;
    white_n == 0 ? x = 0 : x = 7;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};
        switch (names_white[y]) {
        case 'T': {
            white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[y], 0)));
            break;
        }
        case 'C':
            white.push_back(std::shared_ptr<Piece>(new Knight(pos, names_white[y], 0)));
            break;
        case 'A':
            white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[y], 0)));
            break;
        case 'D':
            white.push_back(std::shared_ptr<Piece>(new Queen(pos, names_white[y], 0)));
            break;
        case 'R':
            white.push_back(std::shared_ptr<Piece>(new King(pos, names_white[y], 0)));
            break;
        }
        board[x][y] = white.back();
    }
    white_n == 0 ? x = 1 : x = 6;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};
        white.push_back(std::shared_ptr<Piece>(new Pawn2(pos, names_white[8], 0)));
        board[x][y] = white.back();
    }
    black_n == 0 ? x = 0 : x = 7;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};

        switch (names_black[y]) {
        case 't':
            black.push_back(std::shared_ptr<Piece>(new Rook(pos, names_black[y], 1)));
            break;
        case 'c':
            black.push_back(std::shared_ptr<Piece>(new Knight(pos, names_black[y], 1)));
            break;
        case 'a':
            black.push_back(std::shared_ptr<Piece>(new Rook(pos, names_black[y], 1)));
            break;
        case 'd':
            black.push_back(std::shared_ptr<Piece>(new Queen(pos, names_black[y], 1)));
            break;
        case 'r':
            black.push_back(std::shared_ptr<Piece>(new King(pos, names_black[y], 1)));
            break;
        }
        board[x][y] = black.back();
    }
    black_n == 0 ? x = 1 : x = 6;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};
        black.push_back(std::shared_ptr<Piece>(new Pawn7(pos, names_black[8], 1)));
        board[x][y] = black.back();
    }
}


