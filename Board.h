#ifndef BOARD_H
#define BOARD_H

#include "pieces/Piece.h"
#include <memory>
#include <vector>

class Board {
  private:
    std::vector<std::shared_ptr<Piece>> white;
    std::vector<std::shared_ptr<Piece>> black;

    /*
    ehh, qua è un po' difficile. In input prende la posizione dei pezzi che non sono pedoni dei bianchi e dei
    neri e facciamo che se avete qualche domanda ci sentiamo una volta su discord che è complicata la questione
    Se volete semplificare... smack
    */
    void initialize_board(int, int);

  public:
    Board();
    // solo per ricordarmi, poi va implementato tutto nel cpp
	
    void print();
    std::vector<std::vector<std::shared_ptr<Piece>>> board;
};

#endif