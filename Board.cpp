// Tommaso Zanon, 2000146
#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn1.h"
#include "pieces/Pawn6.h"
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
    for (short x = 0; x < 8; x++) {
        board.push_back(std::vector<std::shared_ptr<Piece>>());
        for (short y = 0; y < 8; y++) {
            std::vector<short> pos{x, y};
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
    short row_n = 8;
    for (short row = 7; row >= 0; row--) {
        std::cout << row_n-- << " |";
        for (short col = 0; col < 8; col++) {
            if (board[row][col] != nullptr)
                std::cout << board[row][col]->to_char() << "|";
        }
        std::cout << std::endl;
        std::cout << "  ";

        for (short i = 0; i <= 16; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
    std::cout << "   ";
    for (short i = 97; i <= 104; i++) {
        std::cout << (char)i << " ";
    }
    std::cout << std::endl;
}

void Board::initialize_board(int white_n, int black_n) {
    short x = white_n;

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
            white.push_back(std::shared_ptr<Piece>(new Bishop(pos, names_white[y], 0)));
            break;
        case 'D':
            white.push_back(std::shared_ptr<Piece>(new Queen(pos, names_white[y], 0)));
            break;
        case 'R':
            white.push_back(std::shared_ptr<Piece>(new King(pos, names_white[y], 0)));
            break;
        }
        board[x][y].reset();
        board[x][y] = white.back();
    }
    white_n == 0 ? x = 1 : x = 6;
    if (x == 1) {
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            white.push_back(std::shared_ptr<Piece>(new Pawn1(pos, names_white[8], 0)));
            board[x][y].reset();
            board[x][y] = white.back();
        }
    } else {
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            white.push_back(std::shared_ptr<Piece>(new Pawn6(pos, names_white[8], 0)));
            board[x][y].reset();
            board[x][y] = white.back();
        }
    }

    x = black_n;
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
            black.push_back(std::shared_ptr<Piece>(new Bishop(pos, names_black[y], 1)));
            break;
        case 'd':
            black.push_back(std::shared_ptr<Piece>(new Queen(pos, names_black[y], 1)));
            break;
        case 'r':
            black.push_back(std::shared_ptr<Piece>(new King(pos, names_black[y], 1)));
            break;
        }
        board[x][y].reset();
        board[x][y] = black.back();
    }
    black_n == 0 ? x = 1 : x = 6;
    if (x == 1) {
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            black.push_back(std::shared_ptr<Piece>(new Pawn1(pos, names_black[8], 1)));
            board[x][y].reset();
            board[x][y] = black.back();
        }
    } else {
        for (short y = 0; y < 8; y++) {
            short pos[2]{x, y};
            black.push_back(std::shared_ptr<Piece>(new Pawn6(pos, names_black[8], 1)));
            board[x][y].reset();
            board[x][y] = black.back();
        }
    }
}

std::string convert(std::vector<short> pos1, std::vector<short> pos2) {
    std::string res = (char)(pos1[1] + 1 + 96) + std::to_string(pos1[0] + 1) + " " + (char)(pos2[1] + 1 + 96) + std::to_string(pos2[0] + 1);
    return res;
}
void Board::find_and_erase_piece(std::shared_ptr<Piece> piece) {
    std::vector<std::shared_ptr<Piece>> piece_list;
    piece->get_color() == 0 ? piece_list = white : piece_list = black;
    short i = 0;
    while (i < piece_list.size()) {
        if (piece == piece_list[i]) {
            piece_list[i].reset();
            piece_list.erase(piece_list.begin() + i);
            i = piece_list.size();
        }
        i++;
    }
}

bool Board::move(std::vector<short> pos1, std::vector<short> pos2) {

    auto piece = board[pos1[0]][pos1[1]];
    convert(pos1, pos2);
    // en passant
    std::vector<short> del{0, 0};
    if (board[pos2[0]][pos2[1]]->to_char() == ' ') {
        if (board[pos2[0]][pos2[1]]->get_position()[1] != board[pos1[0]][pos1[1]]->get_position()[1]) {
            if (pos2[0] > pos1[0]) {
                auto piece = board[pos2[0] - 1][pos2[1]];
                find_and_erase_piece(piece);
                std::vector<short> del{pos2[0], pos2[1]};
                del[0]--;

                board[pos2[0] - 1][pos2[1]] = std::shared_ptr<Piece>(new Space(del, ' '));
            } else if (pos2[0] < pos1[0]) {
                auto piece = board[pos2[0] + 1][pos2[1]];
                find_and_erase_piece(piece);
                std::vector<short> del{pos2[0], pos2[1]};
                del[0]++;

                board[pos2[0] + 1][pos2[1]] = std::shared_ptr<Piece>(new Space(del, ' '));
            }
        }
        board[pos2[0]][pos2[1]]->set_pos(pos1);
        board[pos1[0]][pos1[1]]->set_pos(pos2);

        board[pos1[0]][pos1[1]] = board[pos2[0]][pos2[1]];
        board[pos2[0]][pos2[1]] = piece;
        // piece.reset();
    } else if (piece->get_color() != board[pos2[0]][pos2[1]]->get_color()) {

        // toglie il pezzo mangiato dalla lista dei pezzi di quel colore
        if (board[pos2[0]][pos2[1]]->get_color() == 0) {
            short i = 0;
            while (i < white.size()) {
                auto p = white[i];
                if (p == board[pos2[0]][pos2[1]]) {
                    white.erase(white.begin() + i);
                    i = white.size();
                }
                i++;
            }
        } else {
            short i = 0;
            while (i < black.size()) {
                auto p = black[i];
                if (p == board[pos2[0]][pos2[1]]) {
                    black.erase(black.begin() + i);
                    i = black.size();
                }
                i++;
            }
        }

        board[pos1[0]][pos1[1]] = std::shared_ptr<Piece>(new Space(pos1, ' '));
        piece->set_pos(pos2);

        board[pos2[0]][pos2[1]] = piece;
        // piece.reset();
    } else {
        return false;
    }

    last_move[0] = convert(pos1, pos2);
    last_move[1] = piece->to_char();
    return true;
}

bool Board::discovery_move(std::vector<short> pos1, std::vector<short> pos2) {

    auto piece = board[pos1[0]][pos1[1]];

    if (board[pos2[0]][pos2[1]]->to_char() == ' ') {

        board[pos1[0]][pos1[1]] = board[pos2[0]][pos2[1]];
        board[pos2[0]][pos2[1]] = piece;
        piece.reset();
    } else if (piece->get_color() != board[pos2[0]][pos2[1]]->get_color()) {

        if (board[pos2[0]][pos2[1]]->get_color() != board[pos1[0]][pos1[1]]->get_color()) {

            board[pos1[0]][pos1[1]] = std::shared_ptr<Piece>(new Space(pos1, ' '));

            board[pos2[0]][pos2[1]] = piece;
            piece.reset();
        } else {
            return false;
        }
    }
    return true;
}