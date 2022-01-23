#ifndef DRAW_H
#define DRAW_H

#include "get_moves.h"
#include "Board.h"
#include "special_moves.h"
#include "pieces/Piece.h"
#include "pieces/King.h"

/*Method stalemate: verifies if there are the conditions for a stalemate
  *input: a Board (game's chessboard)
  *output: true if it is stalemate, false otherwise
*/
bool stalemate(Board& b);

/*se si fanno più di 50 mosse in cc
bool to_much_moves();

//se si ripete una disposizione nella scacchiera per 3 volte                                     NEL MAIN
bool threefold_repetition();

//se per 50 mosse non si mangiano pezzi o non si muovono pedoni
bool fifty_move_rule();
*/

/*Method dead_position: verifies if there aren't enougth pieces to win a game
  *input: a Board (game's chessboard)
  *output: true if there aren't enougth pieces, false otherwise
*/
bool dead_position(Board& b);
#endif