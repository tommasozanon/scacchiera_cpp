#include "Pawn1.h"
#include <vector>

std::vector<std::vector<short>> Pawn1::get_allowed_moves() {
    std::vector<std::vector<short>> list{};
    std::vector<short> pos = get_position();
    pos[0] += 1;
    list.push_back(pos);
    if (first_move) {
        pos[0] += 1;
        list.push_back(pos);
    }
    pos = get_position();
    pos[0] += 1;
    if (pos[0] < 8) {
        pos[1] -= 1;
        if (pos[1] >= 0)
            list.push_back(pos);
        pos[1] += 2;
        if (pos[1] < 8)
            list.push_back(pos);
    }
    return list;
}

std::vector<short> Pawn1::get_position() {
    return position;
}