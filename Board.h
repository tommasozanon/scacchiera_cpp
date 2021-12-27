#include "pieces/Piece.h"
#include <vector>

class Board {
  private:
    std::vector<std::vector<Piece>> board;
	std::vector<std::vector<char>> board_repr;

  public:
    Board();  //costruttore di una board per implementazione
	Board(char a);  //costruttore di una board per output

	int is_empty(short pos[2]); //-1 se vuota, altrimenti 0 se c'e' un bianco  o 1 se c'e' un nero
    void print();
};