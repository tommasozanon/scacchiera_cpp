#ifndef BOARD_H
#define BOARD_H

#include "pieces/Piece.h"
#include <memory>
#include <vector>

class Board {
  private:
    std::vector<std::shared_ptr<Piece>> white;
    std::vector<std::shared_ptr<Piece>> black;
    std::vector<std::vector<std::shared_ptr<Piece>>> board;

    void initialize_board();

  public:
    Board();
    // solo per ricordarmi, poi va implementato tutto nel cpp
	
    void print();
};

#endif