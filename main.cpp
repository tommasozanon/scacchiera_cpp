#include "Board.h"
#include <iostream>
#include <vector>

#include "pieces/Queen.h"
int main() {
    short pos[2]{0, 0};
    Queen r(pos, 'B');
    std::vector<std::vector<short>> all_pos = r.get_allowed_moves();

    for (int i = 0; i < all_pos.size(); i++) {
        std::cout << "(" << all_pos[i][0] << ", " << all_pos[i][1] << ")" << std::endl;
    }
    return 0;
}