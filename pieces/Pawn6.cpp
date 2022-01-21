#include "Pawn6.h"
#include <vector>
std::vector<std::vector<short>> Pawn6::get_allowed_moves() {
    std::vector<std::vector<short>> list{};
    std::vector<short> pos = get_position();

    pos[0] -= 1;
    list.push_back(pos);
    if (first_move) {
        pos[0] -= 1;
        list.push_back(pos);
    }
    pos = get_position();
    pos[0] -= 1;
    pos[1] -= 1;
    list.push_back(pos);
    pos[1] += 2;
    list.push_back(pos);
    return list;
}

std::vector<short> Pawn6::get_position() {
    return position;
}