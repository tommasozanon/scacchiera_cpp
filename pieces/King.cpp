#include "King.h"
#include <cmath>
#include <vector>

std::vector<std::vector<short>> King::get_allowed_moves() {
    const std::vector<short> pos{King::get_position()};

    std::vector<std::vector<short>> allowed_moves;
    std::vector<short> all_p{0, 4};

    for (short x = -1; x < 2; x++) {
        for (short y = -1; y < 2; y++) {
            if (!(std::abs(x) + std::abs(y)) == 0) {
                all_p[0] = pos[0] + x;
                all_p[1] = pos[1] + y;

                if (all_p[0] >= 0 && all_p[0] < 8 && all_p[1] >= 0 && all_p[1] < 8)
                    allowed_moves.push_back(all_p);
            }
        }
    }
    if (first_move) {
        all_p[0] = pos[0];
        all_p[1] = 6;
        allowed_moves.push_back(all_p);
        all_p[1] = 2;
        allowed_moves.push_back(all_p);
    }
    return allowed_moves;
}