#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <vector>
class Rook: public Piece{
	
private:
    std::vector<short> position;
    bool first_move = true;
    //int value = 5;
    char repr;
	int colour;

public:
	Rook(short pos[2], int clr);

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();

};
#endif