#include "pieces/Piece.h"
#include <vector>

class Board {
  private:
    std::vector<std::vector<Piece>> board;

  public:
    Board();
    // solo per ricordarmi, poi va implementato tutto nel cpp

    void print();
};