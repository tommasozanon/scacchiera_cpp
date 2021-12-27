#include "Board.h"
#include "pieces/Pawn2.h"
#include "pieces/Pawn7.h"
#include "pieces/Rook.h"
#include <iostream>
#include <cstdlib>

Board::Board() { //costruttore scacchiera NON output
    short pos[2]{0, 0};
	int colour = rand()%2; //estrazione di uno tra bianchi e neri (0->bianchi, 1->neri)
	
	//pedoni
    for (short col = 0; col < 8; col++) { 
        pos[0] = 1;
        pos[1] = col;
        board[1][col] = Pawn2(pos, colour); //assegnazione colore
        pos[0] = 6;
        pos[1] = col;
        board[6][col] = Pawn7(pos, 1-colour); //assegnazione altro colore
    }
    //board[1][0].to_string();
	
	//torri
	short Rook_pos[2]{0,0};
	board[0][0]=Rook(Rook_pos, colour);
	pos[1]=7;
	board[0][7]=Rook(Rook_pos, colour);
	pos[0]=7;
	board[7][7]=Rook(Rook_pos, 1-colour);
	pos[1]=0;
	board[7][0]=Rook(Rook_pos, 1-colour);
}

Board::Board(char a){
	for (int c=0; c<8; c++){
		board_repr[0][c]=board[0][c].to_string();
		board_repr[1][c]=board[1][c].to_string();
		board_repr[6][c]=board[6][c].to_string();
		board_repr[7][c]=board[7][c].to_string();
	}
}

void Board::print() {
    for (short row = 0; row < 8; row++) {
        for (short col = 0; col < 8; col++) {
            board[row][col].to_string();
        }
        std::cout << std::endl;
    }
}

int Board::is_empty(short pos[2]){
	char p = board_repr[pos[0]][pos[1]];
	
	if (p>=65 && p<=90) {return 1;}
	else if (p>=97 && p<=122) {return 0;}
	else {return -1;}
}