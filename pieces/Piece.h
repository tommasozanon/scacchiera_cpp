#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <string>
#include <vector>
class Piece {
  public:
    Piece(const Piece&) = delete;
    Piece& operator=(Piece const&);
    /*Metodo to_char: restituisce la rappresentazione del pezzo
	* input: -
    * output: la lettera rappresentativa del pezzo
    */
    virtual char to_char() = 0;

    /*Metodo set_pos: permette di impostare una nuova posizione
    * input: un array di short (la nuova posizione)
	* output: -
    */
    virtual void set_pos(short[2]) = 0;

    /* Metodo get_allowed_moves: studia le possibili mosse di un pezzo
	* input: -
	* output: tutte le posizioni possibili che il pezzo può fare in una scacchiera senza altri pezzi
    */
    virtual std::vector<std::vector<short>> get_allowed_moves() = 0;
	
	/*Metodo get_position: restituisce la posizione attuale del pezzo
	* input: -
    * output: la posizione attuale del pezzo
    */
    virtual std::vector<short> get_position() = 0;

//variabili d'istanza
  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

    Piece(){};

    //~Piece(){};
};

#endif