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

/*Method dead_position: verifies if there aren't enougth pieces to win a game
  *input: a Board (game's chessboard)
  *output: true if there aren't enougth pieces, false otherwise
*/
bool dead_position(Board& b);
#endif