#include "memory"
#include "pieces/Piece.h"
#include <cctype>
#include <vector>

/*
prende in input la scacchiera, le allowed_moves del pezzo e il pezzo stesso. Si verifica in quale delle allowed_moves
si può effettivamente spostare il pezzo. Ritorna la lista di posizioni nelle quale si può spostare il pezzo
*/
std::vector<std::vector<short>> get_moves(std::vector<std::vector<std::shared_ptr<Piece>>>& board, std::vector<std::vector<short>>& moves, std::shared_ptr<Piece>& piece);