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
    Pawn2(short pos[2], char c) : position{pos[0], pos[1]}, repr{c} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();
    char to_char() { return repr; }

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
};

#endif