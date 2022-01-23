#include "draw.h"
#include "Board.h"
#include "special_moves.h"
#include "pieces/Piece.h"
#include "pieces/King.h"

#include <vector>

bool stalemate(Board& b){
	std::vector<std::vector<std::shared_ptr<Piece>>> board = b.get_board();
	std::vector<std::vector<short>> all_white_moves;
	std::vector<std::vector<short>> all_black_moves;
	auto reW = b.white.at(0);
	
	for (int i=0; i<b.white.size(); i++){
		if (std::tolower(b.white.at(i)->to_char())=='r'){
			reW = b.white.at(i);
		}
		std::vector<std::vector<short>> piece_moves = get_moves(b, b.white.at(i));
		for (int j=0; j<piece_moves.size(); j++){
			all_white_moves.push_back(piece_moves.at(j));
		}
	}
	
	auto reB = b.black.at(0);
	for (int i=0; i<b.black.size(); i++){
		if (std::tolower(b.black.at(i)->to_char())=='r'){
			reB = b.black.at(i);
		}
		std::vector<std::vector<short>> piece_moves = get_moves(b, b.black.at(i));
		for (int j=0; j<piece_moves.size(); j++){
			all_black_moves.push_back(piece_moves.at(j));
		}
	}

	if (all_white_moves.size()==0 && !is_check(reW->get_position(), board, 0))
		return true;
	if (all_black_moves.size()==0 && !is_check(reB->get_position(), board, 1))
		return true;
		
	return false;
}

bool dead_position(Board& b){	
	if (b.white.size()>2 || b.black.size()>2)
		return false;
	
	if (b.white.size()==1 && b.black.size()==1)
		return true;
	
	if (b.white.size()==1 && b.black.size()==2){
		auto r = b.black.at(0);
		int index=0;
		if (std::tolower(b.black.at(1)->to_char())=='r'){
			r = b.black.at(1);
			index=1;
		}
		
		char other_piece = std::tolower(b.black.at(1-index)->to_char());
		if (other_piece=='c' || other_piece=='a')
			return true;
	}
	
	if (b.white.size()==2 && b.white.size()==1){
		auto r = b.white.at(0);
		int index=0;
		if (std::tolower(b.white.at(1)->to_char())=='r'){
			r = b.white.at(1);
			index=1;
		}
		
		char other_piece = std::tolower(b.white.at(1-index)->to_char());
		if (other_piece=='c' || other_piece=='a')
			return true;
	}
	
	return false;
}

#include "Board.cpp"