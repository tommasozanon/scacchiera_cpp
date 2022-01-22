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
vector<short> player_move(Board b);
vector<short> computer_move(Board b, const shared_ptr<Piece>& piece);

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

			player_move(chessboard);

			//playerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());

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
/*	if (playerColour==0){ //gioca prima il player
		while (!is_checkmate() && !is_draw()){
			
			player_move(b);
			
			srand(time(NULL));
			int random_piece = rand()%b.black.size();
			computer_move(b, b.black.at(random_piece));

			b.print();
		}
		//if (is_checkmate()){}
		//if (is_draw()){}
	}
	else{ //gioca prima il computer
		while (!is_checkmate() && !is_draw()){ //-->metodi non ancora scritti, danno undefined reference
			
			srand(time(NULL));
			int random_piece = rand()%b.white.size();
			computer_move(b, b.white.at(random_piece));

			//modifico b prima di pasarla a player_move 
			b.move();

			player_move(b);

			b.print();
		}
		
		//if (is_checkmate()){}
		//if (is_draw()){}
	
	}*/
}


/* Idea: nel vettore di get_moves cerco a caso una mossa e restituisco quella
	input: 	-la board;
 			-il pezzo alla posizione di partenza (condizioni verificate nel main);
 	utput:	-posizione dove muoviamo il pezzo (estratta a caso)
			 o la posizione di partenza se il pezzo non ha mosse;
*/
// NON HO TESTATO NULLA

//computer_move
vector<short> computer_move(Board b, const shared_ptr<Piece>& piece){
	vector<vector<short>> possible_moves = get_moves(b, piece);
	
	if (possible_moves.size()<=0) {return piece->get_position();}
	
	srand(time(NULL));
	int final_pos = rand()%possible_moves.size();
	
	return possible_moves.at(final_pos);
}

//player_move(Board)
vector<short> player_move(Board b){
	vector<vector<shared_ptr<Piece>>> board = b.get_board();
	
	vector<short> where = {-1,-1};
	
	/*controllo che l'input sia di cinque caratteri LNSLN (lettera, numero, spazio, lettera, numero)
	obbligatoriamente così da aver le condizioni rispettate sempre per il check della validità e per il
	passaggio al file log per il replay
	*/

	string s[2];
	cin>>s[0];
	cin>>s[1];
	
	//numero di stringhe inserite (boh)
	int dimension=sizeof(s)/sizeof(s[0]);
	
	if (dimension!=2){
		cout<<"rtvgy"<<"\n";
		return where;
	}
	//validita'
	if (s[0].length()!=2 || s[1].length()!=2){
		return where;
	}
	
	int column1 = tolower(s[0][0])-97;
	int row1 = s[0][1]-49;
	int column2 = tolower(s[1][0])-97;
	int row2 = s[1][1]-49;
	
	if (column1<0 || column2<0 || column1>7 || column2>7){
		return where;
	}
	
	if (row1<0 || row2<0 || row1>7 || row2>7){
		return where;
	}
	
	//muovo il pezzo se e' possibile
	vector<short> initial_pos = {row1, column1};	
	vector<short> final_pos = {row2, column2};
	
	
	vector<vector<short>> all_moves = get_moves(b, board[row1][column1]);
	for (int i=0; i<all_moves.size(); i++){
		if(all_moves[i][0] == row2 && all_moves[i][1] == column2){
			b.move (initial_pos, final_pos);
			where = final_pos;
		}
	}
	return where;
}
//remove undefined references
#include "Board.cpp" 
#include "special_moves.cpp"