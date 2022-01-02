#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <vector>
class Piece {
  public:
    Piece(const Piece&) = delete;
    Piece& operator=(Piece const&);
    /*
    ritorna la lettera rappresentativa del pezzo
    */
    virtual char to_char() = 0;

    /*
    permette di impostare una nuova posizione
    */
    virtual void set_pos(short[2]) = 0;

    /*
    ritorna tutte le posizioni possibili che il pezzo può fare in una scacchiera senza altri pezzi
    */
    virtual std::vector<std::vector<short>> get_allowed_moves() = 0;
    /*
    ritorna la posizione attuale del pezzo
    */
    virtual std::vector<short> get_position() = 0;
    virtual int get_color() = 0;

  protected:
    std::vector<short> position;
    bool first_move = true;
    int value;
    char repr;
    int color;
    Piece(){};

    //~Piece(){};
};

#endif