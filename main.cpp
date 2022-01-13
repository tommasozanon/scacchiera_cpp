#include "Board.h"
#include "get_moves.h"
#include "pieces/Space.h"
#include "special_moves.h"
#include <iostream>
#include <vector>

int main() {
    Board b;
    std::cout << "Per la promozione, scrivere: coord1 coord2 carattere_del_pezzo_in_cui_si_vuole_promuovere_il_pedone (default donna)\n";
    // std::vector<std::vector<short>> moves = get_moves(b.board, b.board[1][7]);
    /*
    for (int i = 0; i < moves.size(); i++) {
        std::cout << "( " << moves[i][0] << ", " << moves[i][1] << ")" << std::endl;
    }


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
    pos1[0] = 6;
    pos1[1] = 3;
    pos2[0] = 5;
    pos2[1] = 3;
    std::cout << "discovery check: " << is_discovery_check(b, pos1, pos2) << std::endl;

    std::vector<std::vector<short>> moves = get_moves(b.board, b.board[1][1]);
    for (int i = 0; i < moves.size(); i++) {
        std::cout << "( " << moves[i][0] + 1 << ", " << moves[i][1] + 1 << ")" << std::endl;
    }
    pos1[0] = 1;
    pos1[1] = 1;
    pos2[0] = 5;
    pos2[1] = 1;

    b.move(pos1, pos2);
    b.print();

    pos1[0] = 0;
    pos1[1] = 4;
    pos2[0] = 0;
    pos2[1] = 0;
    std::cout << "castling: " << is_castling(pos1, pos2, b.board) << std::endl;
    pos1[0] = 6;
    pos1[1] = 3;
    pos2[0] = 5;
    pos2[1] = 3;
    std::cout << "discovery check: " << is_discovery_check(b, pos1, pos2) << std::endl;

    pos1[0] = 1;
    pos1[1] = 0;
    pos2[0] = 7;
    pos2[1] = 0;
    b.move(pos1, pos2);
    std::cout << promotion(b, b.board[7][0], 'd') << std::endl;
    b.print();
	
	//test alfiere, torre e donna
	pos1[0] = 0;
    pos1[1] = 2;
    pos2[0] = 3;
    pos2[1] = 4;
	b.move(pos1, pos2);
	b.print();
    std::vector<std::vector<short>> movess = get_moves(b.board, b.board[3][4]);
    for (int i = 0; i < movess.size(); i++) {
		char a = movess[i][1]+1+96;
        std::cout << "( " << movess[i][0] + 1 << ", " << a << ")" << std::endl;
    }
    return 0;
}