// Giulio Piccolin, 2008817
#include "memory"
#include "pieces/King.h"
#include "pieces/Piece.h"
#include "special_moves.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

std::vector<std::vector<short>> get_moves(Board& b, const std::shared_ptr<Piece>& piece) {
    std::vector<std::vector<std::shared_ptr<Piece>>> board = b.get_board();
    char c = piece->to_char();
    std::vector<std::vector<short>> moves = piece->get_allowed_moves();

    if (std::tolower(c) == 'p') { // pedone-----------------------------------------
        short i = 0;
        while (i < moves.size()) {

            if (piece->get_position()[1] == moves[i][1]) {
                if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                    moves.erase(moves.begin() + i, moves.end() - 1);
                } else {
                    i++;
                }
            } else {
                if (board[moves[i][0]][moves[i][1]]->to_char() == ' ' || board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                    moves.erase(moves.begin() + i);
                } else {
                    i++;
                }
            }
        }

        // controllo eventuale inchiodatura
        i = 0;
        std::vector<short> pos = piece->get_position();
        std::vector<short> new_pos{0, 0};
        while (i < moves.size()) {
            new_pos[0] = moves[i][0];
            new_pos[1] = moves[i][1];
            if (is_discovery_check(b, pos, new_pos)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }

        // en passant
        std::vector<short> a{0, 0};
        short x = 0;
        if (piece->get_position()[0] == 3) {
            if (std::tolower(b.last_move[1][0]) == 'p') {

                if ((char)(b.last_move[0][3]) == (char)(piece->get_position()[1] + 98)) {
                    x = ((int)(b.last_move[0][3])) - 97;

                } else if ((char)(b.last_move[0][3]) == (char)(piece->get_position()[1] + 96)) {
                    x = ((int)(b.last_move[0][3])) - 96;
                    std::cout << " bbbbbb " << std::endl;
                }
                a[0] = 2;
                a[1] = x;
                std::cout << x << std::endl;
                moves.push_back(a);
            }
            return moves;
        } else if (piece->get_position()[0] == 4) {
            if (std::tolower(b.last_move[1][0]) == 'p') {

                if ((char)(b.last_move[0][3]) == (char)(piece->get_position()[1] + 97)) {
                    x = ((int)(b.last_move[0][3])) - 97;

                } else if ((char)(b.last_move[0][3]) == (char)(piece->get_position()[1] + 95)) {
                    x = ((int)(b.last_move[0][3])) - 95;
                }
                a[0] = 5;
                a[1] = x;
                std::cout << x << std::endl;
                moves.push_back(a);
            }
        }

        return moves;
    } else if (std::tolower(c) == 'c') { // cavallo-----------------------------
        short i = 0;
        while (i < moves.size()) {
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }

        // controllo eventuale inchiodatura
        i = 0;
        std::vector<short> pos = piece->get_position();
        std::vector<short> new_pos{0, 0};
        while (i < moves.size()) {
            new_pos[0] = moves[i][0];
            new_pos[1] = moves[i][1];
            if (is_discovery_check(b, pos, new_pos)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::tolower(c) == 't') { // torre------------------------------------
        std::vector<std::vector<short>> up_column;
        std::vector<std::vector<short>> down_column;
        std::vector<std::vector<short>> dx_row;
        std::vector<std::vector<short>> sx_row;

        std::vector<short> pos = piece->get_position();
        int c = pos[1];
        int r = pos[0];

        // suddivisione semi-righe e semi-colonne
        while (c == moves[0][1]) {
            if (r > moves[0][0]) {
                down_column.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                up_column.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }
        while (r == moves[0][0]) {
            if (c > moves[0][1]) {
                sx_row.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                dx_row.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }
        // inversione vettori sx_row e down_column
        for (int j = 0; j < (int)(sx_row.size() / 2); j++) {
            std::vector<short> temp = sx_row[sx_row.size() - 1 - j];
            sx_row[sx_row.size() - 1 - j] = sx_row[0 + j];
            sx_row[0 + j] = temp;
        }

        for (int j = 0; j < (int)(down_column.size() / 2); j++) {
            std::vector<short> temp = down_column[down_column.size() - 1 - j];
            down_column[down_column.size() - 1 - j] = down_column[0 + j];
            down_column[0 + j] = temp;
        }

        // cancellazione mosse non valide
        int i = 0;
        while (i < up_column.size()) {
            if (board[up_column[i][0]][up_column[i][1]]->to_char() != ' ') {
                if (board[up_column[i][0]][up_column[i][1]]->get_color() == piece->get_color()) {
                    up_column.erase(up_column.begin() + i, up_column.end());
                } else {
                    up_column.erase(up_column.begin() + i + 1, up_column.end());
                    i = up_column.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < down_column.size()) {
            if (board[down_column[i][0]][down_column[i][1]]->to_char() != ' ') {
                if (board[down_column[i][0]][down_column[i][1]]->get_color() == piece->get_color()) {
                    down_column.erase(down_column.begin() + i, down_column.end());
                } else {
                    down_column.erase(down_column.begin() + i + 1, down_column.end());
                    i = down_column.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < sx_row.size()) {
            if (board[sx_row[i][0]][sx_row[i][1]]->to_char() != ' ') {
                if (board[sx_row[i][0]][sx_row[i][1]]->get_color() == piece->get_color()) {
                    sx_row.erase(sx_row.begin() + i, sx_row.end());
                } else {
                    sx_row.erase(sx_row.begin() + i + 1, sx_row.end());
                    i = sx_row.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < dx_row.size()) {
            if (board[dx_row[i][0]][dx_row[i][1]]->to_char() != ' ') {
                if (board[dx_row[i][0]][dx_row[i][1]]->get_color() == piece->get_color()) {
                    dx_row.erase(dx_row.begin() + i, dx_row.end());
                } else {
                    dx_row.erase(dx_row.begin() + i + 1, dx_row.end());
                    i = dx_row.size();
                }
            } else {
                i++;
            }
        }

        // fusione dei 4 vettori
        while (!up_column.empty()) {
            moves.push_back(up_column.front());
            up_column.erase(up_column.begin());
        }

        while (!down_column.empty()) {
            moves.push_back(down_column.front());
            down_column.erase(down_column.begin());
        }

        while (!sx_row.empty()) {
            moves.push_back(sx_row.back());
            sx_row.erase(sx_row.end());
        }

        while (!dx_row.empty()) {
            moves.push_back(dx_row.front());
            dx_row.erase(dx_row.begin());
        }

        // controllo eventuale inchiodatura
        i = 0;
        std::vector<short> new_pos{0, 0};
        while (i < moves.size()) {
            new_pos[0] = moves[i][0];
            new_pos[1] = moves[i][1];
            if (is_discovery_check(b, pos, new_pos)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::towlower(c) == 'a') { // alfiere--------------------------------------------------------
        std::vector<std::vector<short>> high_right;
        std::vector<std::vector<short>> high_left;
        std::vector<std::vector<short>> low_right;
        std::vector<std::vector<short>> low_left;

        std::vector<short> pos = piece->get_position();
        int r = pos[0];
        int c = pos[1];
        // suddivisione di tutte le mosse per diagonale di appartenenza (alla fine del while moves e' vuoto)
        while (!moves.empty()) {
            if (moves[0][0] < r && moves[0][1] > c) {
                low_right.push_back(moves.front());
                moves.erase(moves.begin());
            } else if (moves[0][0] < r && moves[0][1] < c) {
                low_left.push_back(moves.front());
                moves.erase(moves.begin());
            } else if (moves[0][0] > r && moves[0][1] > c) {
                high_right.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                high_left.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }

        // eventuale cancellazione di mosse non accessibili
        int i = 0;
        while (i < high_right.size()) {
            if (board[high_right[i][0]][high_right[i][1]]->to_char() != ' ') {
                if (board[high_right[i][0]][high_right[i][1]]->get_color() != piece->get_color()) {
                    i++;
                } // gestione della mangiata
                high_right.erase(high_right.begin() + i, high_right.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < high_left.size()) {
            if (board[high_left[i][0]][high_left[i][1]]->to_char() != ' ') {
                if (board[high_left[i][0]][high_left[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                high_left.erase(high_left.begin() + i, high_left.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < low_right.size()) {
            if (board[low_right[i][0]][low_right[i][1]]->to_char() != ' ') {
                if (board[low_right[i][0]][low_right[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                low_right.erase(low_right.begin() + i, low_right.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < low_left.size()) {
            if (board[low_left[i][0]][low_left[i][1]]->to_char() != ' ') {
                if (board[low_left[i][0]][low_left[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                low_left.erase(low_left.begin() + i, low_left.end());
            } else {
                i++;
            }
        }

        // riassemblamento di tutte le mosse (in ordine DIVERSO da quello di input)
        while (!high_right.empty()) {
            moves.push_back(high_right.front());
            high_right.erase(high_right.begin());
        }

        while (!low_right.empty()) {
            moves.push_back(low_right.front());
            low_right.erase(low_right.begin());
        }

        while (!high_left.empty()) {
            moves.push_back(high_left.front());
            high_left.erase(high_left.begin());
        }

        while (!low_left.empty()) {
            moves.push_back(low_left.front());
            low_left.erase(low_left.begin());
        }

        // controllo eventuale inchiodatura
        i = 0;
        std::vector<short> new_pos{0, 0};
        while (i < moves.size()) {
            new_pos[0] = moves[i][0];
            new_pos[1] = moves[i][1];
            if (is_discovery_check(b, pos, new_pos)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::tolower(c) == 'd') { // regina-------------------------------------------------
        std::vector<std::vector<short>> up_column;
        std::vector<std::vector<short>> down_column;
        std::vector<std::vector<short>> dx_row;
        std::vector<std::vector<short>> sx_row;
        std::vector<std::vector<short>> high_right;
        std::vector<std::vector<short>> high_left;
        std::vector<std::vector<short>> low_right;
        std::vector<std::vector<short>> low_left;

        std::vector<short> pos = piece->get_position();
        int c = pos[1];
        int r = pos[0];

        // suddivisione semi-righe, semi-colonne e diagonali
        while (c == moves[0][1]) {
            if (r > moves[0][0]) {
                down_column.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                up_column.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }
        while (r == moves[0][0]) {
            if (c > moves[0][1]) {
                sx_row.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                dx_row.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }

        while (!moves.empty()) {
            if (moves[0][0] < r && moves[0][1] > c) {
                low_right.push_back(moves.front());
                moves.erase(moves.begin());
            } else if (moves[0][0] < r && moves[0][1] < c) {
                low_left.push_back(moves.front());
                moves.erase(moves.begin());
            } else if (moves[0][0] > r && moves[0][1] > c) {
                high_right.push_back(moves.front());
                moves.erase(moves.begin());
            } else {
                high_left.push_back(moves.front());
                moves.erase(moves.begin());
            }
        }

        // inversione vettori sx_row e down_column
        for (int j = 0; j < (int)(sx_row.size() / 2); j++) {
            std::vector<short> temp = sx_row[sx_row.size() - 1 - j];
            sx_row[sx_row.size() - 1 - j] = sx_row[0 + j];
            sx_row[0 + j] = temp;
        }

        for (int j = 0; j < (int)(down_column.size() / 2); j++) {
            std::vector<short> temp = down_column[down_column.size() - 1 - j];
            down_column[down_column.size() - 1 - j] = down_column[0 + j];
            down_column[0 + j] = temp;
        }

        // cancellazione mosse non valide
        // semi-righe e semi-colonne
        int i = 0;
        while (i < up_column.size()) {
            if (board[up_column[i][0]][up_column[i][1]]->to_char() != ' ') {
                if (board[up_column[i][0]][up_column[i][1]]->get_color() == piece->get_color()) {
                    up_column.erase(up_column.begin() + i, up_column.end());
                } else {
                    up_column.erase(up_column.begin() + i + 1, up_column.end());
                    i = up_column.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < down_column.size()) {
            if (board[down_column[i][0]][down_column[i][1]]->to_char() != ' ') {
                if (board[down_column[i][0]][down_column[i][1]]->get_color() == piece->get_color()) {
                    down_column.erase(down_column.begin() + i, down_column.end());
                } else {
                    down_column.erase(down_column.begin() + i + 1, down_column.end());
                    i = down_column.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < sx_row.size()) {
            if (board[sx_row[i][0]][sx_row[i][1]]->to_char() != ' ') {
                if (board[sx_row[i][0]][sx_row[i][1]]->get_color() == piece->get_color()) {
                    sx_row.erase(sx_row.begin() + i, sx_row.end());
                } else {
                    sx_row.erase(sx_row.begin() + i + 1, sx_row.end());
                    i = sx_row.size();
                }
            } else {
                i++;
            }
        }

        i = 0;
        while (i < dx_row.size()) {
            if (board[dx_row[i][0]][dx_row[i][1]]->to_char() != ' ') {
                if (board[dx_row[i][0]][dx_row[i][1]]->get_color() == piece->get_color()) {
                    dx_row.erase(dx_row.begin() + i, dx_row.end());
                } else {
                    dx_row.erase(dx_row.begin() + i + 1, dx_row.end());
                    i = dx_row.size();
                }
            } else {
                i++;
            }
        }
        // controllo diagonali
        i = 0;
        while (i < high_right.size()) {
            if (board[high_right[i][0]][high_right[i][1]]->to_char() != ' ') {
                if (board[high_right[i][0]][high_right[i][1]]->get_color() != piece->get_color()) {
                    i++;
                } // gestione della mangiata
                high_right.erase(high_right.begin() + i, high_right.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < high_left.size()) {
            if (board[high_left[i][0]][high_left[i][1]]->to_char() != ' ') {
                if (board[high_left[i][0]][high_left[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                high_left.erase(high_left.begin() + i, high_left.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < low_right.size()) {
            if (board[low_right[i][0]][low_right[i][1]]->to_char() != ' ') {
                if (board[low_right[i][0]][low_right[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                low_right.erase(low_right.begin() + i, low_right.end());
            } else {
                i++;
            }
        }

        i = 0;
        while (i < low_left.size()) {
            if (board[low_left[i][0]][low_left[i][1]]->to_char() != ' ') {
                if (board[low_left[i][0]][low_left[i][1]]->get_color() != piece->get_color()) {
                    i++;
                }
                low_left.erase(low_left.begin() + i, low_left.end());
            } else {
                i++;
            }
        }

        // riassemblaggio di tutte le mosse (in ordine DIVERSO da quello di input)
        while (!up_column.empty()) {
            moves.push_back(up_column.front());
            up_column.erase(up_column.begin());
        }

        while (!down_column.empty()) {
            moves.push_back(down_column.front());
            down_column.erase(down_column.begin());
        }

        while (!sx_row.empty()) {
            moves.push_back(sx_row.back());
            sx_row.erase(sx_row.end());
        }

        while (!dx_row.empty()) {
            moves.push_back(dx_row.front());
            dx_row.erase(dx_row.begin());
        }

        while (!high_right.empty()) {
            moves.push_back(high_right.front());
            high_right.erase(high_right.begin());
        }

        while (!low_right.empty()) {
            moves.push_back(low_right.front());
            low_right.erase(low_right.begin());
        }

        while (!high_left.empty()) {
            moves.push_back(high_left.front());
            high_left.erase(high_left.begin());
        }

        while (!low_left.empty()) {
            moves.push_back(low_left.front());
            low_left.erase(low_left.begin());
        }

        // controllo eventuale inchiodatura
        i = 0;
        std::vector<short> new_pos{0, 0};
        while (i < moves.size()) {
            new_pos[0] = moves[i][0];
            new_pos[1] = moves[i][1];
            if (is_discovery_check(b, pos, new_pos)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
        return moves;
    } else if (std::tolower(c) == 'r') { // re-------------------------------------------------------------
        short i = 0;
        std::vector<short> pos = piece->get_position();

        if (piece->is_first_move()) {
            // controllo tutte le mosse tranne le ultime due (gli arrocchi)
            while (i < moves.size() - 2) {
                std::vector<short> postn = {moves[i][0], moves[i][1]};
                if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                    if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color() || is_check(postn, board, piece->get_color())) {
                        moves.erase(moves.begin() + i);
                    } else {
                        i++;
                    }
                } else {
                    if (is_check(postn, board, piece->get_color())) {
                        moves.erase(moves.begin() + i);
                    } else {
                        i++;
                    }
                }
            }
            // controllo arrocchi
            i = 0;
            std::vector<short> tower1_pos = {pos[0], 0};
            std::vector<short> tower2_pos = {pos[0], 7};

            if (!is_castling(pos, tower1_pos, board)) {
                moves.erase(moves.end() - 1);

                if (!is_castling(pos, tower2_pos, board)) {
                    moves.erase(moves.end() - 1);
                }
            } else {
                if (!is_castling(pos, tower2_pos, board)) {
                    moves.erase(moves.end() - 2);
                }
            }
        } else {
            // controllo tutte le mosse
            while (i < moves.size()) {
                std::vector<short> postn = {moves[i][0], moves[i][1]};
                if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                    if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color() || is_check(postn, board, piece->get_color())) {
                        moves.erase(moves.begin() + i);
                    } else {
                        i++;
                    }
                } else {
                    if (is_check(postn, board, piece->get_color())) {
                        moves.erase(moves.begin() + i);
                    } else {
                        i++;
                    }
                }
            }
        }

        // controllo che i pezzi che posso mangiare non siano coperti
        i = 0;
        while (i < moves.size()) {
            std::vector<short> temp = {moves[i][0], moves[i][1]};
            if (is_discovery_check(b, pos, temp)) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }

        return moves;
    }
}