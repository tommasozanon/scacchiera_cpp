#include "Bishop.h"
#include <vector>

std::vector<std::vector<short>> Bishop::get_allowed_moves() {
    const std::vector<short> pos{Bishop::get_position()};

    std::vector<std::vector<short>> allowed_moves;
    std::vector<short> all_p{0, 2};

    for (short i = 1; i < 8; i++) {
        if (pos[0] + i < 8 && pos[1] + i < 8) {
            all_p[0] = pos[0] + i;
            all_p[1] = pos[1] + i;
            allowed_moves.push_back(all_p);
        }
        if (pos[0] + i < 8 && pos[1] - i >= 0) {
            all_p[0] = pos[0] + i;
            all_p[1] = pos[1] - i;
            allowed_moves.push_back(all_p);
        }
        if (pos[0] - i >= 0 && pos[1] - i >= 0) {
            all_p[0] = pos[0] - i;
            all_p[1] = pos[1] - i;
            allowed_moves.push_back(all_p);
        }
        if (pos[0] - i >= 0 && pos[1] + i < 8) {
            all_p[0] = pos[0] - i;
            all_p[1] = pos[1] + i;
            allowed_moves.push_back(all_p);
        }
    }

    return allowed_moves;
}