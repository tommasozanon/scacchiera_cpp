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

/*input: il pezzo che si vuole promuovere
 *output: il puntatore al pezzo eventualmente promosso
 */
std::shared_ptr<Piece> promotion(std::shared_ptr<Piece> piece, char promote = 'd');

// patta
bool is_draw();

// stallo, iterare nella lista dei pezzi e vedere se ci sono mosse possibili

bool is_en_passant(short[2]);
#endif