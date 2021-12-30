#include "Rook.h"
#include <vector>

std::vector<std::vector<short>> Rook::get_allowed_moves() {
    const std::vector<short> pos{Rook::get_position()};

    std::vector<std::vector<short>> allowed_moves;
    std::vector<short> all_p{0, 0};

    all_p[1] = pos[1];
    for (short i = 0; i < 8; i++) {
        if (!(i == pos[0])) {
            all_p[0] = i;
            allowed_moves.push_back(all_p);
        }
    }

    all_p[0] = pos[0];
    for (short i = 0; i < 8; i++) {
        if (!(i == pos[1])) {
            all_p[1] = i;
            allowed_moves.push_back(all_p);
        }
    }
    return allowed_moves;
}