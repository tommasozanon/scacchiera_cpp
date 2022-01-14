#ifndef BOARD_H
#define BOARD_H

#include "pieces/Piece.h"
#include <memory>
#include <vector>

class Board {
  private:
    /*
    ehh, qua è un po' difficile. In input prende la posizione dei pezzi che non sono pedoni dei bianchi e dei
    neri e facciamo che se avete qualche domanda ci sentiamo una volta su discord che è complicata la questione
    Se volete semplificare... smack
    */
    void initialize_board(int, int);

  public:
    std::vector<std::shared_ptr<Piece>> white;
    std::vector<std::shared_ptr<Piece>> black;

    Board();
    // solo per ricordarmi, poi va implementato tutto nel cpp

    void print();
    std::vector<std::vector<std::shared_ptr<Piece>>> board;

    // ritorna true se lo spostamento è andato a buon fine
    bool move(std::vector<short> pos1, std::vector<short> pos2);

    std::vector<std::vector<std::shared_ptr<Piece>>>& get_board() { return board; }
};

#endif