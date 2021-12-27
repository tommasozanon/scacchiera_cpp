#include "Pawn2.h"
#include <vector>

std::vector<std::vector<short>> Pawn2::get_allowed_moves() {
    std::vector<std::vector<short>> list{};
    std::vector<short> move = get_position();
    move[0] += 1;
    list.push_back(move);
    if (first_move) {
        move[0] += 1;
        list.push_back(move);
        first_move = false;
    }
    return list;
}

std::vector<short> Pawn2::get_position() {
    return position;
}

Pawn2::Pawn2(short pos[2], int clr) : position{pos[0], pos[1]} {
	colour=clr;
	if (colour==0) {repr='p';}
	else{repr='P';}
} 

