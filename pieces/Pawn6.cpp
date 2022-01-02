#include "Pawn6.h"
#include <vector>

std::vector<std::vector<short>> Pawn6::get_allowed_moves() {
    std::vector<std::vector<short>> list{};
    std::vector<short> move = get_position();
    move[0] -= 1;
    list.push_back(move);
    if (first_move) {
        move[0] -= 1;
        list.push_back(move);
        first_move = false;
    }
    return list;
}

std::vector<short> Pawn6::get_position() {
    return position;
}