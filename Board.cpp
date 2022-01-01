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
    // std::vector<std::vector<std::shared_ptr<Piece>>> board{};
    std::shared_ptr<Piece> p;
    for (short x = 0; x < 8; x++) {
        board.push_back(std::vector<std::shared_ptr<Piece>>());
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            board[x].push_back(std::shared_ptr<Piece>(new Space(pos, ' ')));
        }
    }

    Board::initialize_board();
}

void Board::print() {
    std::cout << "print" << std::endl;
    /*
    auto p = white[1];
    std::cout << p->to_char();
    */

    for (short row = 7; row >= 0; row--) {
        for (short col = 7; col >= 0; col--) {
            // std::cout << board[row][col];

            if (board[row][col] != nullptr)
                std::cout << board[row][col]->to_char() << "|";
        }
        std::cout << std::endl;
        for (short i = 0; i < 16; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

void Board::initialize_board() {
    srand(time(NULL));
    int random = rand() % 2;
    random = 0;
    if (random == 0) {
        short x = 0;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            switch (names_white[y]) {
            case 'T': {
                white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[y])));
                break;
            }
            case 'C':
                white.push_back(std::shared_ptr<Piece>(new Knight(pos, names_white[y])));
                break;
            case 'A':
                white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[y])));
                break;
            case 'D':
                white.push_back(std::shared_ptr<Piece>(new Queen(pos, names_white[y])));
                break;
            case 'R':
                white.push_back(std::shared_ptr<Piece>(new King(pos, names_white[y])));
                break;
            }
            board[x][y] = white.back();
        }
        x = 1;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            white.push_back(std::shared_ptr<Piece>(new Pawn2(pos, names_white[8])));
            board[x][y] = white.back();
        }
        x = 7;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};

            switch (names_black[y]) {
            case 't':
                black.push_back(std::shared_ptr<Piece>(new Rook(pos, names_black[y])));
                break;
            case 'c':
                black.push_back(std::shared_ptr<Piece>(new Knight(pos, names_black[y])));
                break;
            case 'a':
                black.push_back(std::shared_ptr<Piece>(new Rook(pos, names_black[y])));
                break;
            case 'd':
                black.push_back(std::shared_ptr<Piece>(new Queen(pos, names_black[y])));
                break;
            case 'r':
                black.push_back(std::shared_ptr<Piece>(new King(pos, names_black[y])));
                break;
            }
            board[x][y] = black.back();
        }
        x = 6;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            black.push_back(std::shared_ptr<Piece>(new Pawn7(pos, names_black[8])));
            board[x][y] = black.back();
        }
        // std::cout << board.size();
        // white in basso 1,2
        // black in alto 7,8
    } else {
        exit;
    }
}
