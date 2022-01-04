#ifndef SPECIAL_MOVES_H
#define SPECIAL_MOVES_H

#include "pieces/Piece.h"
#include <memory>
#include <vector>

bool is_check(std::vector<short>, const std::vector<std::vector<std::shared_ptr<Piece>>>&, short my_color);

bool is_en_passant(short[2]);

// non chiaro, cosa vuole in input. Pensare ad un modo migliore per organizzare arrocco
bool is_castling(std::vector<short> pos_re, std::vector<short> pos_torre, const std::vector<std::vector<std::shared_ptr<Piece>>>& board);

bool is_promotion(short[2]);

// da guardare in inglese lol
bool scacco_di_scoperta();

#endif