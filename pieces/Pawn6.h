#ifndef PAWN7_H
#define PAWN7_H

#include "Piece.h"
#include <vector>

class Pawn6 : public Piece {
    // variabili d'istanza
  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;
    int color;

  public:
    Pawn6(short pos[2], char c, int col) : position{pos[0], pos[1]}, repr{c}, color{col} {};

    // Metodi derivati da Piece: si consulti Piece per la descrizione di ciascuno di essi
    char to_char() { return repr; }

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();

    void set_pos(std::vector<short> pos) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
    int get_color() { return color; }
};

#endif