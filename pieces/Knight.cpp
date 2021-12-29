#include "Knight.h"
#include <cmath>
#include <vector>

std::vector<std::vector<short>> Knight::get_allowed_moves() {
    const std::vector<short> pos{Knight::get_position()};

    std::vector<std::vector<short>> allowed_moves;
    std::vector<short> all_p{0, 2};

    for (short x = -2; x < 3; x++) {
        for (short y = -2; y < 3; y++) {
            if (std::abs(x) + std::abs(y) == 3) {
                all_p[0] = pos[0] + x;
                all_p[1] = pos[1] + y;
                if (all_p[0] >= 0 && all_p[0] < 8 && all_p[1] >= 0 && all_p[1] < 8)
                    allowed_moves.push_back(all_p);
            }
        }
    }
    return allowed_moves;
}