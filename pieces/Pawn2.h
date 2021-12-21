#ifndef PAWN2_H
#define PAWN2_H

#include "Piece.h"
#include <vector>

class Pawn2 : public Piece {
  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

  public:
    Pawn2(short pos[2]) : position{pos[0], pos[1]}, repr{'P'} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();
};

#endif