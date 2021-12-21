#include <vector>

class Piece {
  protected:
    std::vector<short[2]> position;
    bool first_move = true;
    int value = 1;
    char repr;

    Piece() = delete;
    virtual std::vector<short[2][2]> get_allowed_moves() = 0;
    virtual std::vector<short[2]> get_position() = 0;
};