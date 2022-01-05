#include "Board.h"
#include "get_moves.h"
#include "pieces/Space.h"
#include "special_moves.h"
#include <iostream>
#include <vector>

int main() {
    Board b;

    /*
    std::vector<std::vector<short>> mov = b.board[0][1]->get_allowed_moves();
    for (int i = 0; i < mov.size(); i++) {
        std::cout << "( " << mov[i][0] << ", " << mov[i][1] << ")" << std::endl;
    }

    std::vector<std::vector<short>> moves = get_moves(b.board, b.board[0][1]);

    for (int i = 0; i < moves.size(); i++) {
        std::cout << "( " << moves[i][0] << ", " << moves[i][1] << ")" << std::endl;
    }
    */

    std::vector<short> pos1{0, 3};
    std::vector<short> pos2{5, 2};
    b.move(pos1, pos2);
    /*
    pos1[0] = 0;
    pos2[0] = 2;
    b.move(pos1, pos2);
    pos1[1] = 1;
    pos2[1] = 2;
    b.move(pos1, pos2);
    pos1[1] = 2;
    pos2[1] = 1;
    b.move(pos1, pos2);
    */
    b.print();
    // std::cout << is_check(b.board[7][4]->get_position(), b.board) << std::endl;

    // std::vector<std::vector<short>> moves = get_moves(b.board, b.board[2][3]);
    /*
    for (int i = 0; i < moves.size(); i++) {
        std::cout << "( " << moves[i][0] + 1 << ", " << moves[i][1] + 1 << ")" << std::endl;
    }
    */
    pos1[0] = 1;
    pos1[1] = 3;
    pos2[0] = 5;
    pos2[1] = 3;
    std::cout << "discovery check: " << is_discovery_check(b, pos1, pos2) << std::endl;

    return 0;
}