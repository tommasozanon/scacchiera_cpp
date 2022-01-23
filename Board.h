// Tommaso Zanon, 2000146
#ifndef BOARD_H
#define BOARD_H

#include "pieces/Piece.h"
#include <memory>
#include <string>
#include <vector>

class Board {
  private:
    void initialize_board(int, int);

  public:
    std::vector<std::shared_ptr<Piece>> white;
    std::vector<std::shared_ptr<Piece>> black;
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
    std::vector<std::string> last_move{"", ""};

    /*Constructor of Board: initialize a chessboard with all the pieces in the right place
     *input: -
     */
    Board();

    /*Method print: print the chessboard as it is when 'print' is called
     *input: -
     *output: -
     */
    void print();

    /*Method move: move the piece in 'pos1' to 'pos2' if it is possible
      *input: - vector of shorts (pos1 --> where the piece is)
                                     -vector of shorts (pos2 --> where the piece goes)
      *output: true if the move is allowed, false otherwise
    */
    bool move(std::vector<short> pos1, std::vector<short> pos2);
    bool discovery_move(std::vector<short> pos1, std::vector<short> pos2);

    /*Method get_board(): returns the chessboard's matrix of shorts
     *input: -
     *output: a matrix of shorts
     */
    std::vector<std::vector<std::shared_ptr<Piece>>>& get_board() { return board; }
};

#endif