// Giulio Piccolin, 2008817
#ifndef SPACE_H
#define SPACE_H

#include "Piece.h"
#include <vector>
class Space : public Piece {

  private:
    std::vector<short> position;
    bool first_move = true;
    char repr;

  public:
    // Constructor
    Space(std::vector<short> pos, char c) : position{pos[0], pos[1]}, repr{c} {};

    // Methods: see Piece.h for all their description
    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position() { return position; };
    char to_char() { return repr; }

    void set_pos(std::vector<short> pos) {
        position[0] = pos[0];
        position[1] = pos[1];
    };

    int get_color() { return -1; }
    bool is_first_move() { return first_move; }
};

#endif