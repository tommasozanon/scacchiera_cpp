#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "pieces/Piece.h"
#include <iostream>
#include <vector>
class Game {

    std::vector<Piece> white;
    std::vector<Piece> black;

    short turn = 0;
    Game(){};
};

#endif