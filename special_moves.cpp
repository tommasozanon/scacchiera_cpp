#include "pieces/Piece.h"
#include <iostream>
#include <memory>
#include <vector>

/*
 *input: la casella sulla quale bisogna eseguire la verifica dello scacco, la scacchiera
 *output: vero se c'è scacco, falso altrimenti
 */
bool is_check(std::vector<short> pos, const std::vector<std::vector<std::shared_ptr<Piece>>>& board) {
    std::vector<std::vector<short>> allowed_moves;
    std::vector<short> all_p{0, 0};
    // check sulle righe e colonne (movimento della torre)
    all_p[1] = pos[1];
    short i = 1;
    bool up = true;
    bool down = true;
    while (up || down) {
        all_p[0] = pos[0] + i;
        if (all_p[0] < 8 && up && board[all_p[0]][all_p[1]]->to_char() != ' ') {
            if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                allowed_moves.push_back(all_p);
                up = false;
            } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                up = false;
            }
        }

        all_p[0] = pos[0] - i;
        if (all_p[0] >= 0 && down && board[all_p[0]][all_p[1]]->to_char() != ' ') {
            if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                allowed_moves.push_back(all_p);
                down = false;
            } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                down = false;
            }
        }
        if (i > 8) {
            up = false;
            down = false;
        }
        i++;
    }

    up = true;
    down = true;

    all_p[0] = pos[0];
    i = 1;
    while (up || down) {
        all_p[1] = pos[1] + i;
        if (all_p[1] < 8 && up && board[all_p[0]][all_p[1]]->to_char() != ' ') {
            if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                allowed_moves.push_back(all_p);
                up = false;
            } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                up = false;
            }
        }

        all_p[1] = pos[1] - i;
        if (all_p[1] >= 0 && down && board[all_p[0]][all_p[1]]->to_char() != ' ') {
            if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                allowed_moves.push_back(all_p);
                down = false;
            } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                down = false;
            }
        }
        if (i > 8) {
            up = false;
            down = false;
        }
        i++;
    }
    // check sulle diagonali (movimento dell'alfiere)

    bool ne = true;
    bool nw = true;
    bool se = true;
    bool sw = true;

    i = 1;

    while (ne || nw || se || sw) {
        if (ne) {
            all_p[0] = pos[0] + i;
            all_p[1] = pos[1] + i;
            if (all_p[0] < 8 && all_p[1] < 8) {
                if (board[all_p[0]][all_p[1]]->to_char() != ' ') {
                    if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                        allowed_moves.push_back(all_p);
                        ne = false;
                    } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                        ne = false;
                    }
                }
            }
        }
        if (nw) {
            all_p[0] = pos[0] + i;
            all_p[1] = pos[1] - i;
            if (all_p[0] < 8 && all_p[1] >= 0) {
                if (board[all_p[0]][all_p[1]]->to_char() != ' ') {
                    if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                        allowed_moves.push_back(all_p);
                        nw = false;
                    } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                        nw = false;
                    }
                }
            }
        }
        if (se) {
            all_p[0] = pos[0] - i;
            all_p[1] = pos[1] + i;
            if (all_p[0] >= 0 && all_p[1] < 8) {
                if (board[all_p[0]][all_p[1]]->to_char() != ' ') {
                    if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                        allowed_moves.push_back(all_p);
                        se = false;
                    } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                        se = false;
                    }
                }
            }
        }
        if (sw) {
            all_p[0] = pos[0] - i;
            all_p[1] = pos[1] - i;
            if (all_p[0] >= 0 && all_p[1] >= 0) {
                if (board[all_p[0]][all_p[1]]->to_char() != ' ') {
                    if (board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color()) {
                        allowed_moves.push_back(all_p);
                        sw = false;
                    } else if (board[all_p[0]][all_p[1]]->get_color() == board[pos[0]][pos[1]]->get_color()) {
                        sw = false;
                    }
                }
            }
        }
        if (i > 8) {
            ne = nw = se = sw = false;
        }
        i++;
    }

    // check sul movimento del cavallo
    for (short x = -2; x < 3; x++) {
        for (short y = -2; y < 3; y++) {
            if (std::abs(x) + std::abs(y) == 3) {
                all_p[0] = pos[0] + x;
                all_p[1] = pos[1] + y;
                if (all_p[0] >= 0 && all_p[0] < 8 && all_p[1] >= 0 && all_p[1] < 8 && board[all_p[0]][all_p[1]]->to_char() != ' ' && board[all_p[0]][all_p[1]]->get_color() != board[pos[0]][pos[1]]->get_color())
                    allowed_moves.push_back(all_p);
            }
        }
    }

    /*
    for (int i = 0; i < allowed_moves.size(); i++) {
        std::cout << "(" << allowed_moves[i][0] + 1 << ", " << allowed_moves[i][1] + 1 << ")\n";
    }
    */
    for (short i = 0; i < allowed_moves.size(); i++) {
        auto piece = board[allowed_moves[i][0]][allowed_moves[i][1]];
        std::vector<std::vector<short>> piece_moves = piece->get_allowed_moves();
        short a = 0;

        while (a < piece_moves.size()) {

            if (piece_moves[a][0] == pos[0] && piece_moves[a][1] == pos[1]) {
                return true;
            }
            a++;
        }
    }
    return false;
}