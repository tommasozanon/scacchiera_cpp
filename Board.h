#ifndef BOARD_H
#define BOARD_H

#include "pieces/Piece.h"
#include <vector>

class Board {
  private:
    std::vector<Piece*> white;
    std::vector<Piece*> black;

  public:
    Board(int);
    // solo per ricordarmi, poi va implementato tutto nel cpp

    void print();
};

#endif