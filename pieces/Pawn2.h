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
    int color;

  public:
    Pawn2(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();
    char to_char() { return repr; }

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
    int get_color() { return color; }
};

#endif