#ifndef SPECIAL_MOVES_H
#define SPECIAL_MOVES_H

#include "Board.h"
#include "pieces/Piece.h"
#include <memory>
#include <vector>

bool is_check(std::vector<short>, const std::vector<std::vector<std::shared_ptr<Piece>>>&, short my_color);

// non chiaro, cosa vuole in input. Pensare ad un modo migliore per organizzare arrocco
bool is_castling(std::vector<short> pos_re, std::vector<short> pos_torre, const std::vector<std::vector<std::shared_ptr<Piece>>>& board);

// scacco di scoperta
bool is_discovery_check(Board board, std::vector<short> pos1, std::vector<short> pos2);

/*input: il pezzo che si vuole promuovere
 *output: il puntatore al pezzo eventualmente promosso
 */
std::shared_ptr<Piece> promotion(std::shared_ptr<Piece> piece, char promote = 'd');

// patta
bool is_draw();

// scacco matto
bool is_checkmate();

bool is_en_passant(short[2]);
#endif