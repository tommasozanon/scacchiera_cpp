#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <vector>
class Bishop : public Piece {

  private:
    std::vector<short> position;
    bool first_move = true;
    // int value = 3;
    char repr;

  public:
    Bishop(short pos[2], char c) : position{pos[0], pos[1]}, repr{c} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position() { return position; };
    char to_char() { return repr; }

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
};

#endif