#ifndef PAWN7_H
#define PAWN7_H

#include "Piece.h"
#include <vector>

class Pawn7 : public Piece {
	//variabili d'istanza
protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

public:
	//Costruttore
    Pawn7(short pos[2], char c) : position{pos[0], pos[1]}, repr{c} {};

	//Metodi derivati da Piece: si consulti Piece per la descrizione di ciascuno di essi
    char to_char() { return repr; }

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };
};

#endif