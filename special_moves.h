// Tommaso Zanon, 2000146
#ifndef SPECIAL_MOVES_H
#define SPECIAL_MOVES_H

#include "Board.h"
#include "pieces/Piece.h"
#include <memory>
#include <vector>

/*Method is_check: verifies check conditions
 *input:	-vector of shorts  (where you verify if it is check)
                                -matrix of pieces (game chessboard)
                                -pieces' colour
 *output: true if is check, false otherwise
*/
bool is_check(std::vector<short> pos, const std::vector<std::vector<std::shared_ptr<Piece>>>& board, short my_color);

/*Method is_castling: verifies castling conditions
 *input:	-vector of shorts (king's position)
                        -vector of shorts (rook's position)
                        -matrix of pieces (game chessboard)
 *output: true if you can castle, false otherwise
*/
bool is_castling(std::vector<short> pos_re, std::vector<short> pos_torre, const std::vector<std::vector<std::shared_ptr<Piece>>>& board);

/*Method is_discovery_check: verifies if a piece can be move without discover his king
 *input:	- a Board (game's chessboard)
                                - vector of shorts (pos1, the position of the piece you want to move)
                                - vector of shorts (pos2, the position where the piece is moved)
 *output: true if you can move, false otherwise
 *
*/
bool is_discovery_check(Board board, std::vector<short> pos1, std::vector<short> pos2);

bool is_checkmate(Board& board, short color);

// da fare

/*Method promotion: verifies if a pawn can be promoted and substitute the old piece with the new one
 *input: - a Board (game's chessboard)
                                - the pawn we want ot promote
                                - a char to suggest what is the new piece: d = queen, t = rook, a = bishop, c=knight
 *output: true if we can promote, false otherwise
 */
bool promotion(Board& b, std::shared_ptr<Piece> piece, char promote = 'd');
#endif