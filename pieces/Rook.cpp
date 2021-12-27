#include "Rook.h"
#include <vector>

std::vector<std::vector<short>> Rook::get_allowed_moves() {
    std::vector<std::vector<short>> list{};
    std::vector<short> move = get_position();
	//righe
	for (int i=move[0]; i<8; i++){	
		move[0]++;
		//SE MOVES NON E' OCCUPATA DA UN PEZZO DELLO STESSO COLORE (break in caso)
		list.push_back(move);
	}
	for (int i=move[0]; i>0; i--){
		move[0]--;
		//SE MOVES NON E' OCCUPATA DA UN PEZZO DELLO STESSO COLORE (break in caso)
		list.push_back(move);
	}
	return list;
}
 
std::vector<short> Rook::get_position() {
	return position;
}

Rook::Rook(short pos[2], int clr) : position{pos[0], pos[1]} {
	colour=clr;
	if (colour==0) {repr='r';} //se bianco lettera minuscola
	else {repr='R';}
}

