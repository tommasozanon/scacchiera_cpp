#include "memory"
#include "pieces/Piece.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

std::vector<std::vector<short>> get_moves(const std::vector<std::vector<std::shared_ptr<Piece>>>& board, const std::shared_ptr<Piece>& piece) {
    char c = piece->to_char();
    std::vector<std::vector<short>> moves = piece->get_allowed_moves();
    // per tutti i casi controllare se c'è scacco di scoperta
    if (std::tolower(c) == 'p') {
        short i = 0;
        while (i < moves.size()) {
            if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
        // controllare se il pedone può mangiare di lato ed eventualmente aggiungere le mosse a moves
    } else if (std::tolower(c) == 'c') {
        short i = 0;
        while (i < moves.size()) {
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::tolower(c) == 't' || std::towlower(c) == 'a') {
        int i = 0;
        while (i < moves.size()) {
            // si può migliorare il codice. Si può usare moves.erase(moves.begin() + i, moves.begin() + i + dove finire di cancellare
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                moves.erase(moves.begin() + c);

            } else {
                i++;
            }
        }
        return moves;

    } else if (std::tolower(c) == 'd') {
        return moves;
    } else if (std::tolower(c) == 'r') {
        return moves;
    }
}