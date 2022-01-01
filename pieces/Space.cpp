#include "Space.h"
#include <vector>

std::vector<std::vector<short>> Space::get_allowed_moves() {
    const std::vector<short> position{Space::get_position()};
    std::vector<std::vector<short>> res{position};
    return res;
}
