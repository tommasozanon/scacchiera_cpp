#include "Board.h"
#include "pieces/Space.h"
#include <iostream>
#include <vector>

int main() {
    /*
    short pos[2]{3, 3};
    Space r(pos, ' ');
    std::vector<std::vector<short>> all_pos = r.get_allowed_moves();

    for (int i = 0; i < all_pos.size(); i++) {
        std::cout << "(" << all_pos[i][0] << ", " << all_pos[i][1] << ")" << std::endl;
    }

    std::cout << r.to_char() << "\aa";
    */
    Board b;
    b.print();

    return 0;
}