#ifndef GET_MOVES_H
#define GET_MOVES_H

#include "memory"
#include "pieces/Piece.h"
#include <cctype>
#include <vector>

/*Method get_moves: verifies what are the allowed moves a piece can do in the game among them all.
 *input:	-matrix of pieces (game chessboard)
                                -the piece
 *output: vector of shorts (all the allowed moves in the current game)
*/
std::vector<std::vector<short>> get_moves(Board& board, const std::shared_ptr<Piece>& piece);
// bool is_protected(Board, std::vector<short>, short);

#endif