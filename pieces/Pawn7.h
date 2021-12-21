#include "Piece.h"
#include <vector>

class Pawn7 : public Piece {
  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

  public:
    Pawn7(short pos[2]) : position{pos[0], pos[1]}, repr{'p'} {};

    std::vector<std::vector<short>> get_allowed_moves();
    std::vector<short> get_position();
};