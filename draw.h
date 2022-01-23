#ifndef DRAW_H
#define DRAW_H

#include "get_moves.h"
#include "Board.h"
#include "special_moves.h"
#include "pieces/Piece.h"
#include "pieces/King.h"

//se un giocatore non ha mosse e non è sotto scacco
bool stalemate(Board& b);

/*se si fanno più di 50 mosse in cc
bool to_much_moves();

//se si ripete una disposizione nella scacchiera per 3 volte                                     NEL MAIN
bool threefold_repetition();

//se per 50 mosse non si mangiano pezzi o non si muovono pedoni
bool fifty_move_rule();
*/

//rimangono solo re e re, re e alfiere contro re o re e cavallo contro re (sarebbero molte di più, ma ciaone)
bool dead_position(Board& b);
#endif