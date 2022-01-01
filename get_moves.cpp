#include "memory"
#include "pieces/Piece.h"
#include <cctype>
#include <vector>

std::vector<std::vector<short>> get_moves(std::vector<std::vector<std::shared_ptr<Piece>>>& board, std::vector<std::vector<short>>& moves, std::shared_ptr<Piece>& piece) {
    char c = piece->to_char();
    // per tutti i casi controllare se c'è scacco di scoperta
    if (std::tolower(c) == 'p') {
        true;
    } else if (std::tolower(c) == 'c') {
        true;
    } else if (std::tolower(c) == 'r' || std::towlower(c) == 'a') {
        true;
    } else if (std::tolower(c) == 'd') {
        true;
    } else if (std::tolower(c) == 'r') {
        // controllare lo scacco
        true;
    }
}