#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"
#include <vector>
class Queen : public Piece {

	//variabili d'istanza
private:
    std::vector<short> position;
    bool first_move = true;
    // int value = 9;
    char repr;
    int color;

  public:
    Queen(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position() { return position; };
    char to_char() { return repr; }

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
    int get_color() { return color; }
};
#endif