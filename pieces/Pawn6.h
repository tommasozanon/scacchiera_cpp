#ifndef PAWN7_H
#define PAWN7_H

#include "Piece.h"
#include <vector>

class Pawn6 : public Piece {

  protected:
    std::vector<short> position;
    bool first_move = true;
    char repr;
    int color;

public:
//Contructor
    Pawn6(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};

// Methods: see Piece.h for all their description
    char to_char() { return repr; }

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();

    void set_pos(std::vector<short> pos) {
        position[0] = pos[0];
        position[1] = pos[1];
        first_move = false;
    };
    int get_color() { return color; }
    bool is_first_move() { return first_move; }
};

#endif