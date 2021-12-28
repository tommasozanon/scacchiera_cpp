#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <vector>
class Piece {
  public:
    Piece(const Piece&) = delete;
    Piece& operator=(Piece const&);

    void set_pos(short pos[2]) {
        position[0] = pos[0];
        position[1] = pos[1];
    };

  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

    Piece(){};
    /*
    ritorna tutte le posizioni possibili che il pezzo può fare in una scacchiera senza altri pezzi
    */
    virtual std::vector<std::vector<short>> get_allowed_moves() = 0;

    /*
    ritorna la posizione attuale del pezzo
    */
    virtual std::vector<short> get_position() = 0;

    /*
    ritorna la lettera rappresentativa del pezzo
    */
    virtual char to_char() = 0;

    /*
    salva nella variabile repr il carattere del pezzo
    */
    virtual void set_char(char) = 0;

    //~Piece(){};
};

#endif