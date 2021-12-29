#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn2.h"
#include "pieces/Pawn7.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>

char names_white[]{'T', 'C', 'A', 'D', 'R', 'A', 'C', 'T', 'P'};
char names_black[]{'t', 'c', 'a', 'd', 'r', 'a', 'c', 't', 'p'};

Board::Board() {
    /*
    srand(time(NULL));
    int random = rand() % 2;
    if (random == 0) {
        short x = 0;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};

            switch (names_white[y]) {
            case 'T':
                white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[y])));
                break;
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
        }
        x = 1;
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            white.push_back(std::shared_ptr<Piece>(new Rook(pos, names_white[8])));
        }


    short x = 7;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};

        switch (names_black[y]) {
        case 'T': {
            Rook R(pos, names_black[y]);
            black.push_back(&R);
            break;
        }
        case 'C': {
            Knight C(pos, names_black[y]);
            black.push_back(&C);
            break;
        }
        case 'A': {
            Bishop B(pos, names_black[y]);
            black.push_back(&B);
            break;
        }
        case 'D': {
            Queen Q(pos, names_black[y]);
            black.push_back(&Q);
            break;
        }
        case 'R': {
            King K(pos, names_black[y]);
            black.push_back(&K);
            break;
        }
        }
        board[x][y] = black.back();
    }
    x = 8;
    for (short y = 0; y < 8; y++) {
        short pos[2]{x, y};
        Pawn7 P(pos, names_black[8]);
        black.push_back(&P);
        board[x][y] = black.back();
    }
}
    */
    // white in basso 1,2
    // black in alto 7,8
    /*
    else {
        exit;
    }
*/
}

void Board::print() {
    std::cout << "print" << std::endl;
    /*
    for (short row = 0; row < 8; row++) {
        for (short col = 0; col < 8; col++) {
            if (board[row][col] != nullptr)
                std::cout << board[row][col]->to_char() << " | ";
        }
        std::cout << std::endl;
    }
    */
}
