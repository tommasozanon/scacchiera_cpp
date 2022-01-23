// Tommaso Zanon, 2000146
#include "Board.h"
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Piece.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include <cctype>
#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

void find_and_erase_piece(std::vector<std::shared_ptr<Piece>>& piece_list, std::shared_ptr<Piece> piece);

bool is_check(std::vector<short> pos, const std::vector<std::vector<std::shared_ptr<Piece>>>& board, short my_color) {
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

    for (short i = 0; i < allowed_moves.size(); i++) {
        auto piece = board[allowed_moves[i][0]][allowed_moves[i][1]];
        if (std::tolower(piece->to_char()) != 'r') {
            std::vector<std::vector<short>> piece_moves = piece->get_allowed_moves();
            short a = 0;
            while (a < piece_moves.size()) {
                // std::cout << piece->to_char() << " (" << piece->get_position()[0] + 1 << ", " << piece->get_position()[1] + 1 << "): " << piece_moves[a][0] + 1 << " | " << piece_moves[a][1] + 1 << "\n";
                // std::cout << piece_moves[a][0] << pos[0] << piece_moves[a][1] << pos[1] << "\n";
                if (piece_moves[a][0] == pos[0] && piece_moves[a][1] == pos[1] && piece->get_color() != my_color) {
                    return true;
                }
                a++;
            }
            piece.reset();
        }
    }
    return false;
}

bool is_castling(std::vector<short> pos_king, std::vector<short> pos_rook, const std::vector<std::vector<std::shared_ptr<Piece>>>& board) {
    if (std::tolower(board[pos_king[0]][pos_king[1]]->to_char()) != 'r' && std::tolower(board[pos_rook[0]][pos_rook[1]]->to_char()) != 't') {
        return false;
    } else if (board[pos_king[0]][pos_king[1]]->is_first_move() && board[pos_rook[0]][pos_rook[1]]->is_first_move()) {
        short x;
        pos_king[1] > pos_rook[1] ? x = pos_rook[1] : x = pos_king[1];
        short end;
        pos_king[1] < pos_rook[1] ? end = pos_rook[1] : end = pos_king[1];
        if (is_check(board[pos_king[0]][x]->get_position(), board, board[pos_king[0]][pos_king[1]]->get_color()))
            return false;
        else {
            x++;
        }
        for (x; x < end; x++) {
            std::vector<short> pos{pos_king[0], x};
            if (board[pos_king[0]][x]->to_char() != ' ' || is_check(pos, board, board[pos_king[0]][pos_king[1]]->get_color())) {
                return false;
            }
        }
        if (is_check(board[pos_king[0]][end]->get_position(), board, board[pos_king[0]][pos_king[1]]->get_color()))
            return false;
    }
    return true;
}

// prima di chiamare discovery check bisogna controllare che pos1 non sia uno spazio vuoto. Controllo da fare nel main
bool is_discovery_check(Board board, std::vector<short> pos1, std::vector<short> pos2) {
    std::vector<std::shared_ptr<Piece>> list_p;
    board.board[pos1[0]][pos1[1]]->get_color() == 1 ? list_p = board.black : list_p = board.white;

    auto p = list_p[0];
    if (board.discovery_move(pos1, pos2)) {
        short i = 0;
        while (i < list_p.size()) {
            p = list_p[i];
            if (std::tolower(p->to_char()) == 'r') {
                i = list_p.size();
            }
            i++;
        }
        if (is_check(p->get_position(), board.board, p->get_color())) {
            return true;
        }
    }
    p.reset();
    return false;
}

// ritorna vero se la promozione è andata a buon fine, falso altrimenti
bool promotion(Board& board, std::shared_ptr<Piece> piece, char promote) {
    std::vector<short> pos = piece->get_position();
    if (!(pos[0] == 0 || pos[0] == 7)) {
        // std::cout << "promozione non valida, il pedone non è arrivato all'ultima riga\n";
        return false;
    }
    promote = std::tolower(promote);
    std::vector<char> allowed_char{'t', 'c', 'a', 'd'};
    bool check = false;
    short i = 0;
    while (!(check) && i < allowed_char.size()) {
        if (promote == allowed_char[i]) {
            check = true;
        }
        i++;
    }
    if (!(check)) {
        // std::cout << "promozione non valida, il pedone carattere inserito non è accettabile\n";
        return false;
    }
    std::vector<std::shared_ptr<Piece>>* list_ptr;
    if (piece->get_color() == 0) {
        find_and_erase_piece(board.white, piece);
        list_ptr = &board.white;
    } else {
        find_and_erase_piece(board.black, piece);
        list_ptr = &board.black;
    }
    if (piece->get_color() == 0) {
        for (int i = 0; i < allowed_char.size(); i++) {
            allowed_char[i] = std::toupper(allowed_char[i]);
        }
    }
    short color = piece->get_color();
    short position[]{pos[0], pos[1]};
    switch (promote) {
    case 'd': {
        list_ptr->push_back(std::shared_ptr<Piece>(new Queen(position, allowed_char[3], color)));
        break;
    }
    case 't': {
        list_ptr->push_back(std::shared_ptr<Piece>(new Rook(position, allowed_char[0], color)));
        break;
    }
    case 'a': {
        list_ptr->push_back(std::shared_ptr<Piece>(new Bishop(position, allowed_char[2], color)));
        break;
    }
    case 'c': {
        list_ptr->push_back(std::shared_ptr<Piece>(new Knight(position, allowed_char[1], color)));
        break;
    }
    }
    board.board[pos[0]][pos[1]].reset();
    board.board[pos[0]][pos[1]] = list_ptr->back();
    piece.reset();
    return true;
}

void find_and_erase_piece(std::vector<std::shared_ptr<Piece>>& piece_list, std::shared_ptr<Piece> piece) {
    auto p = piece_list[0];

    short i = 0;
    while (i < piece_list.size()) {
        p = piece_list[i];
        if (piece == piece_list[i]) {
            piece_list[i].reset();
            piece_list.erase(piece_list.begin() + i);
            i = piece_list.size();
        }
        i++;
    }
}

// il colore del re che voglio verificare
bool is_checkmate(Board& b, short color) {

    std::vector<std::shared_ptr<Piece>> list_p;
    color == 1 ? list_p = b.black : list_p = b.white;

    // get king's pointer

    std::shared_ptr<Piece> king;
    short i = 0;

    while (i < list_p.size()) {
        if (std::tolower(list_p[i]->to_char()) == 'r') {
            king = list_p[i];
            i = list_p.size();
        }
        i++;
    }

    // check if king is under check
    if (!(is_check(king->get_position(), b.board, king->get_color()))) {
        return false;
    }
    // std::cout << "king is under check\n";

    // checking if the king can move in any square
    std::vector<std::vector<short>> king_moves = king->get_allowed_moves();
    i = 0;
    while (i < king_moves.size()) {

        if (!(is_discovery_check(b, king->get_position(), king_moves[i]))) {
            return false;
        }
        i++;
    }

    // check if any piece can avoid the check
    std::vector<std::shared_ptr<Piece>> list_opponent;
    color == 0 ? list_opponent = b.black : list_opponent = b.white;
    i = 0;

    short total_check_counter = 0;

    // analyze every opponent's piece
    while (i < list_opponent.size()) {
        short checks_counter = 0; // indica se sono riuscito a difendermi dallo scacco
        std::vector<std::vector<short>> allowed_moves = list_opponent[i]->get_allowed_moves();
        int c = 0;
        bool check = false;
        // itera finchè non si trova che il pezzo potrebbe avere il re sotto scacco
        while (c < allowed_moves.size() && !check) {
            if (allowed_moves[c][0] == king->get_position()[0] && allowed_moves[c][1] == king->get_position()[1]) {
                check = true;
            }
            c++;
            // si potrebbe controllare quali sono i pezzi che mettono in scacco. Se sono ad esempio cavallo e torre,
            // regina e cavallo , alfiere e torre, alfiere e cavallo allora è scacco matto per forza
        }

        if (check) {
            // se i pezzi mettono il re sotto scacco, verifico se c'è qualche possibilità di difesa
            if (std::tolower(list_opponent[i]->to_char()) == 'c' or std::tolower(list_opponent[i]->to_char()) == 'p') {
                if (is_check(list_opponent[i]->get_position(), b.board, list_opponent[i]->get_color())) {
                    checks_counter++;
                    total_check_counter++;
                }
            } else {
                // per avere una complessità migliore con gli altri pezzi, analizzo solo la riga, colonna o diagonale interessata allo scacco
                int iter = floor((c - 1) / 7);
                if (iter > 0) {
                    allowed_moves.erase(allowed_moves.begin(), allowed_moves.begin() + c * 7);
                }
                if (iter < (int)allowed_moves.size() / 7) {
                    allowed_moves.erase(allowed_moves.begin() + 7, allowed_moves.end());
                }
                c = 0;
                // inserisco nella lista delle mosse possibili anche la posizione del pezzo che può fare queste mosse
                while (c < allowed_moves.size()) {
                    if (allowed_moves[c][0] >= list_opponent[i]->get_position()[0] && allowed_moves[c][1] >= list_opponent[i]->get_position()[1]) {
                        allowed_moves.insert(allowed_moves.begin() + c, list_opponent[i]->get_position());
                        c = allowed_moves.size();
                    }
                    c++;
                }
                if (allowed_moves[6][0] <= list_opponent[i]->get_position()[0] && allowed_moves[6][1] <= list_opponent[i]->get_position()[1]) {
                    allowed_moves.push_back(list_opponent[i]->get_position());
                }
                // tengo solo le caselle(comprese) tra il pezzo che mette sotto scacco e il re
                c = 0;
                bool encounter = false;

                while (c < allowed_moves.size()) {
                    if (!encounter) {
                        if ((allowed_moves[c][0] == king->get_position()[0] && allowed_moves[c][1] == king->get_position()[1]) || (allowed_moves[c][0] == list_p[i]->get_position()[0] && allowed_moves[c][1] == list_p[i]->get_position()[1])) {
                            encounter = true;
                            if (c > 0) {
                                allowed_moves.erase(allowed_moves.begin(), allowed_moves.begin() + c);
                            } else {
                                allowed_moves.erase(allowed_moves.begin());
                            }
                            c = 0;
                        }
                    } else {
                        if ((allowed_moves[c][0] == king->get_position()[0] && allowed_moves[c][1] == king->get_position()[1]) || (allowed_moves[c][0] == list_opponent[i]->get_position()[0] && allowed_moves[c][1] == list_opponent[i]->get_position()[1])) {
                            allowed_moves.erase(allowed_moves.begin() + c + 1, allowed_moves.end());
                            c = allowed_moves.size();
                        }
                    }
                    c++;
                }
                if (allowed_moves[0][0] == king->get_position()[0] && allowed_moves[0][1] == king->get_position()[1]) {
                    allowed_moves.erase(allowed_moves.begin());
                } else if ((allowed_moves[allowed_moves.size() - 1][0] == king->get_position()[0] && allowed_moves[allowed_moves.size() - 1][1] == king->get_position()[1])) {
                    allowed_moves.erase(allowed_moves.end() - 1);
                }

                int a = 0;
                while (a < allowed_moves.size()) {
                    if (is_check(allowed_moves[a], b.board, list_opponent[i]->get_color())) {
                        checks_counter++;
                        a = allowed_moves.size();
                    }
                    a++;
                }

                if (checks_counter == 0) {
                    return true;
                } else {
                    total_check_counter++;
                }
            }
        }

        i++;
    }
    // più su controllare se il re può mangiare
    // controllare doppio scacco sulla casella
    if (total_check_counter <= 1) {
        return false;
    }
    return true;
}