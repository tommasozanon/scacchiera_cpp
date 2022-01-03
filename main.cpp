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
    std::vector<short> pos2{6, 3};
    b.move(pos1, pos2);
    b.print();
    std::cout << is_check(b.board[7][4]->get_position(), b.board) << std::endl;
    return 0;
}