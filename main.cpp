#include "Board.h"
#include "get_moves.h"
#include "pieces/Space.h"
#include <iostream>
#include <vector>

int main() {
    Board b;
    b.print();
    /*
    std::vector<std::vector<short>> mov = b.board[0][1]->get_allowed_moves();
    for (int i = 0; i < mov.size(); i++) {
        std::cout << "( " << mov[i][0] << ", " << mov[i][1] << ")" << std::endl;
    }
    */
    std::vector<std::vector<short>> moves = get_moves(b.board, b.board[0][0]);

    for (int i = 0; i < moves.size(); i++) {
        std::cout << "( " << moves[i][0] << ", " << moves[i][1] << ")" << std::endl;
    }
    return 0;
}