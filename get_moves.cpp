#include "memory"
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

    if (std::tolower(c) == 'p') {
        
        short i = 0;
        while (i < moves.size()) {

            if (piece->get_position()[1] == moves[i][1]) {
                if (board[moves[i][0]][moves[i][1]]->to_char() != ' ') {
                    moves.erase(moves.begin() + i);
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
		
		//controllo eventuale inchiodatura
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
		
    } else if (std::tolower(c) == 'c') {
        short i = 0;
        while (i < moves.size()) {
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color()) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
		
		//controllo eventuale inchiodatura
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
		
    } else if (std::tolower(c) == 't') {
        std::vector<std::vector<short>> column;
        std::vector<std::vector<short>> row;

        std::vector<short> pos = piece->get_position();
        int c = pos[1];
        int r = pos[0];

        // suddivisione riga e colonna
        while (c == moves[0][1]) {
            column.push_back(moves.front());
            moves.erase(moves.begin());
        }
        while (r == moves[0][0]) {
            row.push_back(moves.front());
            moves.erase(moves.begin());
        }

        // check colonna
        int i = 0;
        while (i < column.size()) {
            if (board[column[i][0]][column[i][1]]->to_char() != ' ') {

                if (r > column[i][0]) {
                    if (board[column[i][0]][column[i][1]]->get_color() == piece->get_color()) {
                        column.erase(column.begin(), column.begin() + i + 1);
                        i = 0;
                    } else {
                        column.erase(column.begin(), column.begin() + i);
                    }

                }

                else {
                    if (board[column[i][0]][column[i][1]]->get_color() == piece->get_color()) {
                        column.erase(column.begin() + i, column.end());
                    } else {
                        column.erase(column.begin() + i + 1, column.end());
                    }

                    i = column.size();
                }

            } else {
                i++;
            }
        }

        // controllo riga
        i = 0;
        while (i < row.size()) {
            if (board[row[i][0]][row[i][1]]->to_char() != ' ') {
                if (c > row[i][1]) {
                    if (board[row[i][0]][row[i][1]]->get_color() == piece->get_color()) {
                        row.erase(row.begin(), row.begin() + i + 1);
                        i = 0;
                    } else {
                        row.erase(row.begin(), row.begin() + i);
                    }

                }

                else {
                    if (board[row[i][0]][row[i][1]]->get_color() == piece->get_color()) {
                        row.erase(row.begin() + i, row.end());
                    } else {
                        row.erase(row.begin() + i + 1, row.end());
                    }

                    i = row.size();
                }

            } else {
                i++;
            }
        }

        // fusione di riga e colonna finali
        while (column.size() > 0) {
            moves.push_back(column.front());
            column.erase(column.begin());
        }

        while (row.size() > 0) {
            moves.push_back(row.front());
            row.erase(row.begin());
        }
		
		//controllo eventuale inchiodatura
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
		
    } else if (std::towlower(c) == 'a') {
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
		
		//controllo eventuale inchiodatura
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

    } else if (std::tolower(c) == 'd') {
        std::vector<std::vector<short>> column;
        std::vector<std::vector<short>> row;
        std::vector<std::vector<short>> high_right;
        std::vector<std::vector<short>> high_left;
        std::vector<std::vector<short>> low_right;
        std::vector<std::vector<short>> low_left;

        std::vector<short> pos = piece->get_position();
        int c = pos[1];
        int r = pos[0];

        // suddivisione riga, colonna e diagonali
        while (c == moves[0][1]) {
            column.push_back(moves.front());
            moves.erase(moves.begin());
        }
        while (r == moves[0][0]) {
            row.push_back(moves.front());
            moves.erase(moves.begin());
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

        // controllo colonna
        int i = 0;
        while (i < column.size()) {
            if (board[column[i][0]][column[i][1]]->to_char() != ' ') {

                if (r > column[i][0]) {
                    if (board[column[i][0]][column[i][1]]->get_color() == piece->get_color()) {
                        column.erase(column.begin(), column.begin() + i + 1);
                        i = 0;
                    } else {
                        column.erase(column.begin(), column.begin() + i);
                    }

                }

                else {
                    if (board[column[i][0]][column[i][1]]->get_color() == piece->get_color()) {
                        column.erase(column.begin() + i, column.end());
                    } else {
                        column.erase(column.begin() + i + 1, column.end());
                    }

                    i = column.size();
                }

            } else {
                i++;
            }
        }

        // controllo riga
        i = 0;
        while (i < row.size()) {
            if (board[row[i][0]][row[i][1]]->to_char() != ' ') {
                if (c > row[i][1]) {
                    if (board[row[i][0]][row[i][1]]->get_color() == piece->get_color()) {
                        row.erase(row.begin(), row.begin() + i + 1);
                        i = 0;
                    } else {
                        row.erase(row.begin(), row.begin() + i);
                    }

                }

                else {
                    if (board[row[i][0]][row[i][1]]->get_color() == piece->get_color()) {
                        row.erase(row.begin() + i, row.end());
                    } else {
                        row.erase(row.begin() + i + 1, row.end());
                    }

                    i = row.size();
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

        // riassemblamento di tutte le mosse (in ordine DIVERSO da quello di input)
        while (column.size() > 0) {
            moves.push_back(column.front());
            column.erase(column.begin());
        }

        while (row.size() > 0) {
            moves.push_back(row.front());
            row.erase(row.begin());
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
		
		//controllo eventuale inchiodatura
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
		
    }else if (std::tolower(c) == 'r') {
        short i = 0;
		//controllo tutte le mosse tranne le ultime due (gli arrocchi)
        while (i < moves.size()-2) {
            std::vector<short> postn{moves[i][0], moves[i][1]};
            if (board[moves[i][0]][moves[i][1]]->get_color() == piece->get_color() || is_check(postn, board, piece->get_color())) {
                moves.erase(moves.begin() + i);
            } else {
                i++;
            }
        }
		//controllo arrocchi
		i=0;
		std::vector<short> pos = piece->get_position();
		std::vector<short> tower1_pos= {pos[0], 0};
		std::vector<short> tower2_pos= {pos[0], 7};
		
		if (!is_castling(pos, tower1_pos,board)){
			moves.erase(moves.end()-1);
			
			if (!is_castling(pos, tower2_pos,board)){
				moves.erase(moves.end()-1);
			}
		}
		else{
			if (!is_castling(pos, tower2_pos,board)){
				moves.erase(moves.end()-2);
			}
		}
		
        return moves;
    }
}