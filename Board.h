#include "pieces/Piece.h"
#include <vector>

class Board {

    std::vector<std::vector<Piece*>> board;

    Board();
    // solo per ricordarmi, poi va implementato tutto nel cpp

    void print();
};