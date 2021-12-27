#ifndef PAWN7_H
#define PAWN7_H

#include "Piece.h"
#include <vector>

class Pawn7 : public Piece {
  protected:
    std::vector<short> position;
    bool first_move = true;
    //int value = 1;
    char repr;
	int colour;

public:
	Pawn7(short pos[2], int clr);
	
    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();
};
#endif