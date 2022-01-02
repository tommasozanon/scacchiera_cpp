#include <vector>

bool is_check(short[2]);

bool is_en_passant(short[2]);

// non chiaro, cosa vuole in input. Pensare ad un modo migliore per organizzare arrocco
bool is_castling(short[2]);

bool is_promotion(short[2]);

// mangiata classica del pedone. Serve veramente?
bool is_pawn_attack();

// da guardare in inglese lol
bool scacco_di_scoperta();