#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include <vector>
class Bishop : public Piece {

    // variabili d'istanza
  private:
    std::vector<short> position;
    bool first_move = true;
    // int value = 3;
    char repr;
    int color;

  public:
    Bishop(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};
    // Metodi derivati da Piece: si consulti Piece per la descrizione di ciascuno di essi
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