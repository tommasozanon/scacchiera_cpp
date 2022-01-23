#include "Board.h"
#include "special_moves.h"
#include "get_moves.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*Da includere se servono
#include "pieces/Bishop.h"
#include "pieces/King.h"
#include "pieces/Knight.h"
#include "pieces/Pawn1.h"
#include "pieces/Pawn6.h"
#include "pieces/Queen.h"
#include "pieces/Rook.h"
#include "pieces/Space.h"
*/

/*
controllo lunghezza stringa
mosse del giocatore/computer numero di stringhe
gestione della partita cc
creazione del file log (mossa valida da salvare nel file dopo il check, una per ogni riga per il replay)
*/


//methods (besides main)
void playerVScomputer_game(Board b, int playerColour);
string player_move(Board& b);
string computer_move(Board& b, const shared_ptr<Piece>& piece);

//main
int main (int argc, char*  argv[]){ // tutto cio' che ho scritto nel main funziona
	
	//controllo lunghezza input
	if (argc!=2){ 
		cout<<"Insert one valid string to play a game:"<<"\n";
		cout<<"'cc' ---> computer vs computer"<<"\n";
		cout<<"'pc' ---> player vs computer"<<"\n";
		
		return 0;
	}

	//controllo validità input
	switch (argv[1][0]){
		case 'c':{
			//indirizzamento game computer vs computer
			cout<<"'cc' ---> computer vs computer"<<"\n"; //cout di prova
			break;
		}
		case 'p':{
			//indirizzamento game player vs computer
			cout<<"'pc' ---> player vs computer"<<"\n";//cout di prova
			Board chessboard;
			chessboard.print();
			cout<<"How to play:"<<"\n";
			cout<<"Write for example 'A1 B3' to move the piece from A1 to B3"<<"\n";	
			cout<<"Write 'XX XX' to see the chessboard with all the pieces"<<"\n";
			cout<<"ATTENTION: any other string with differnt structure won't be accepted"<<"\n";

			playerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());

			break;
		}
		default: {
			cout<<"Insert a valid string to play a game:"<<"\n";
			cout<<"'cc' ---> computer vs computer"<<"\n";
			cout<<"'pc' ---> player vs computer"<<"\n";
			break;
		}

	}
	return 0;
	
}


void playerVScomputer_game(Board b, int playerColour){
	int i=0;
	if (playerColour==0){ //gioca prima il player
		while (i<4){
			
			string move1 = player_move(b);
			while (move1[0] == '-'){

				move1 = player_move(b);
			}
			
			srand(time(NULL));
			int random_piece = rand()%b.black.size();
			string move2 = computer_move(b, b.black.at(random_piece));
			while (move2[0] == '-'){

				srand(time(NULL));
				random_piece = rand()%b.black.size();
				move2 = computer_move(b, b.black.at(random_piece));
			}

			b.print();
			i++;
		}
		//if (is_checkmate()){}
		//if (is_draw()){}
	}
	else{ //gioca prima il computer
		while (i<4){
			
			srand(time(NULL));
			int random_piece = rand()%b.white.size();
			string move1 = computer_move(b, b.white.at(random_piece));
			while (move1[0] == '-'){

				srand(time(NULL));
				random_piece = rand()%b.white.size();
				move1 = computer_move(b, b.white.at(random_piece));
			}

			b.print();

			string move2 = player_move(b);
			while (move2[0] == '-'){

				move2 = player_move(b);
			}

			if (i==3){b.print();}
			i++;
		}
		
		//if (is_checkmate()){}
		//if (is_draw()){}
	
	}
}

//computer_move
string computer_move(Board& b, const shared_ptr<Piece>& piece){
	vector<vector<short>> possible_moves = get_moves(b, piece);
	
	string where = "----";
	if (possible_moves.size()<=0) {return where;}

	vector<short> initial_pos = piece->get_position();

	srand(time(NULL));
	int final = rand()%possible_moves.size();
	vector<short> final_pos = possible_moves.at(final);

	b.move(initial_pos, final_pos);

	string i1 = to_string(initial_pos.at(0));
	string i2 = to_string(initial_pos.at(1));
	string f1 = to_string(final_pos.at(0));
	string f2 = to_string(final_pos.at(1));
	where = i1+i2+ " " +f1+f2;

	return where;
}

//player_move(Board)
string player_move(Board& b){
	vector<vector<shared_ptr<Piece>>> board = b.get_board();
	
	string where = "----";

	//aquisizione da input della stringa con le coordinate di partenza e arrivo del pezzo
	string positions[2];
	string p1 = positions[0];
	string p2 = positions[1];
	cin>>p1;
	cin>>p2;

	//controllo input
	if (p1.length()!=2 || p2.length()!=2){

		cout<<"Input errato"<<"\n";
		return where;
	}

	int column1 = tolower(p1[0])-97;
	int row1 = p1[1]-49;
	int column2 = tolower(p2[0])-97;
	int row2 = p2[1]-49;

	if (column1<0 || column2<0 || column1>7 || column2>7){


		return where;
	}
	
	if (row1<0 || row2<0 || row1>7 || row2>7){


		return where;
	}
	
	//muovo il pezzo se e' possibile
	vector<short> initial_pos {row1, column1};	
	vector<short> final_pos {row2, column2};
	
	
	vector<vector<short>> all_moves = get_moves(b, board[row1][column1]);
	for (int i=0; i<all_moves.size(); i++){
		if(all_moves[i][0] == row2 && all_moves[i][1] == column2){
			b.move (initial_pos, final_pos);
			where = p1+ " " +p2;
		}
	}

	return where;
}
//remove undefined references
#include "Board.cpp" 
#include "special_moves.cpp"