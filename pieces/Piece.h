#ifndef PIECE_H
#define PIECE_H
#include <vector>

class Piece {
  public:
    Piece(const Piece&) = delete;
    Piece& operator=(Piece const&);
    char to_string() { return repr; }

  protected:
    std::vector<short> position;
    bool first_move = true;
    int value = 1;
    char repr;

    Piece(){};
    virtual std::vector<std::vector<short>> get_allowed_moves() = 0;
    virtual std::vector<short> get_position() = 0;
};

#endif