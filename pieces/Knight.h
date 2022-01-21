#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"
#include <vector>
class Knight : public Piece {

  private:
    std::vector<short> position;
    bool first_move = true;
    char repr;
    int color;

public:
//Constructor
    Knight(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};

// Methods: see Piece.h for all their description
    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position() { return position; };
    char to_char() { return repr; }

    void set_pos(std::vector<short> pos) {
        position[0] = pos[0];
        position[1] = pos[1];
        first_move = false;
    };
    int get_color() { return color; }
    bool is_first_move() { return first_move; }
};
#endif