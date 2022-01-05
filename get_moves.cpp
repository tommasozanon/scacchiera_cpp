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
        while (i < moves.size()) {
            // si può migliorare il codice. Si può usare moves.erase(moves.begin() + i, moves.begin() + i + dove finire di cancellare
            if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()){
					moves.erase(moves.begin() + i);
				}
				i++;
                int temp = i;
                int c = moves[i][1];
                int r = moves[i][0];

                while (c == moves[i][1]) {
                    moves.erase(moves.begin() + i);
                    if (r < piece->get_position()[0]) {
                        i--;
                    } else {
                        i++;
                    }

                    if (i == -1) {
                        i = temp + 1;
                        break;
                    }
                }

                while (r == moves[i][0]) {
                    moves.erase(moves.begin() + i);
                    if (c < piece->get_position()[0]) {
                        i--;
                    } else {
                        i++;
                    }

                    if (i == -1) {
                        i = temp + 1;
                        break;
                    }
                }
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::towlower(c) == 'a') {
		std::vector<vector<short>> high_right;
		std::vector<vector<short>> high_left;
		std::vector<vector<short>> low_right;
		std::vector<vector<short>> low_left;
		
		std::vector<short> pos = piece->get_pos();
		//suddivisione di tutte le mosse per diagonale di appartenenza (alla fine del while moves e' vuoto)
		while (!moves.empty()){
			if (moves[0][0]<pos[0] && moves[0][1]>pos[1]){
				high_right.push_back(moves.erase(moves.begin()));
			}
			else if (moves[0][0]<pos[0] && moves[0][1]<pos[1]){
				high_left.push_back(moves.erase(moves.begin()));
			}
			else if (moves[0][0]>pos[0] && moves[0][1]>pos[1]){
				low_right.push_back(moves.erase(moves.begin()));
			}
			else{
				low_left.push_back(moves.erase(moves.begin()));
			}
		}
		
		//eventuale cancellazione di mosse non accessibili
		int i=0;
		while (i<high_right.size()){
			if (board[high_right[i][0]][high_right[i][1]]->to_char()!= ' '){
				if (board[moves[i][0]][moves[i][1]]->get_color() != piece->get_color()) {i++;} //gestione della mangiata
				high_right.erase(high_right.begin()+i, high_right.end());
			}
			else {i++;}
		}
		
		i=0;
		while (i<high_left.size()){
			if (board[high_left[i][0]][high_left[i][1]]->to_char()!= ' '){
				if (board[moves[i][0]][moves[i][1]]->get_color() != piece->get_color()) {i++;}
				high_left.erase(high_left.begin()+i, high_left.end());
			}
			else {i++;}
		}
		
		i=0;
		while (i<low_rigth.size()){
			if (board[low_rigth[i][0]][low_rigth[i][1]]->to_char()!= ' '){
				if (board[moves[i][0]][moves[i][1]]->get_color() != piece->get_color()) {i++;}
				low_rigth.erase(low_rigth.begin()+i, low_rigth.end());
			}
			else {i++;}
		}
		
		i=0;
		while (i<low_left.size()){
			if (board[low_left[i][0]][low_left[i][1]]->to_char()!= ' '){
				if (board[moves[i][0]][moves[i][1]]->get_color() != piece->get_color()) {i++;}
				low_left.erase(low_left.begin()+i, low_left.end());
			}
			else {i++;}
		}
		
		//riassemblamento di tutte le mosse (in ordine DIVERSO da quello di input (non credo sia un problema no?))
		while (!high_rigth.empty()){
			moves.push_back(high_rigth.erase(high_right.begin()));
		}
		
		while (!low_rigth.empty()){
			moves.push_back(low_rigth.erase(low_right.begin()));
		}
		
		while (!high_left.empty()){
			moves.push_back(high_rigth.erase(high_left.begin()));
		}
		
		while (!low_left.empty()){
			moves.push_back(high_rigth.erase(low_left.begin()));
		}
		
        return moves;
		
    } else if (std::tolower(c) == 'd') {
        return moves;
    }

    else if (std::tolower(c) == 'r') {
        short i = 0;
        while (i < moves.size()) {
            std::vector<short> postn{moves[i][0], moves[i][1]};
            if (board[moves[i][0]][moves[i][1]]->to_char() != ' ' /*|| is_chess(postn)*/) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    }
}