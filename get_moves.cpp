#include "memory"
#include "pieces/Piece.h"
#include "special_moves.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

std::vector<std::vector<short>> get_moves(const std::vector<std::vector<std::shared_ptr<Piece>>>& board, const std::shared_ptr<Piece>& piece) {
    char c = piece->to_char();
    std::vector<std::vector<short>> moves = piece->get_allowed_moves();
    // per tutti i casi controllare special_moves (scacco di scoperta e scacco diretto per il re)
    if (std::tolower(c) == 'p') {
        // todo
        short i = 0;
        // gestire anche la mangiata del pedone
        // todo
        while (i < moves.size()) {

            if (piece->get_position()[1] == moves[i][1]) {
                if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                    moves.erase(moves.begin() + i);
                } else {
                    i++;
                }
            } else {
                if (board[moves[i][0]][moves[i][1]]->to_char() == ' ' || board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                    moves.erase(moves.begin() + i);
                } else {
                    i++;
                }
            }
        }
        return moves;
        // controllare se il pedone può mangiare di lato ed eventualmente aggiungere le mosse a moves
    } else if (std::tolower(c) == 'c') {
        short i = 0;
        while (i < moves.size()) {
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::tolower(c) == 't') {
        int i = 0;
        while (i < moves.size() && i>=0) {
            // si può migliorare il codice. Si può usare moves.erase(moves.begin() + i, moves.begin() + i + dove finire di cancellare
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                //moves.erase(moves.begin() + i);
				int temp = i;
				int c=moves[i][1];
				int r=moves[i][0];
				
				while (c==moves[i][1]) {
					moves.erase(moves.begin() + i);
					if (r<piece->get_position()[0]) {i--;}
					else {i++;}
					
					if (i==-1){
						i=temp+1;
						break;
					}
				}
				
				while (r==moves[i][0]) {
					moves.erase(moves.begin() + i);
					if (c<piece->get_position()[0]) {i--;}
					else {i++;}
					
					if (i==-1){
						i=temp+1;
						break;
					}
				}
            } else {
                i++;
            }
        }
        return moves;

    } 
	else if (std::towlower(c) == 'a'){
		
	}
	return moves;
	else if (std::tolower(c) == 'd') {
	}
        return moves;
    } else if (std::tolower(c) == 'r') {
		 while (i < moves.size()) {
			 std::vector<short> postn{moves[i][0], moves[i][1]};
             if (board[moves[i][0]][moves[i][1]]->to_char() != ' ' /*|| is_chess(postn)*/ ){
                 moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    }
}