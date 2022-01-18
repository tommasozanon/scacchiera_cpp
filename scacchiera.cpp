#include "Board.h"
#include "special_moves.h"
#include "get_moves.h"

#include <cstdlib>

#include <string>
#include <vector>
#include <iostream>
using namespace std;


/*Da includere se servono
Space
Rook
Pawn6
Pawn1
Bishop
Queen
Knight
King
*/

//methods (besides main)
void start_playerVScomputer_game(Board b, int playerColour);
vector<short> player_move(Board b);
vector<short> computer_move(Board b, const std::shared_ptr<Piece>& piece);

//main
int main (int argc, char*  argv[]){ // tutto cio' che ho scritto nel main funziona
	
	//controllo lunghezza input
	if (argc!=2){ 
		cout<<"Insert one valid string to play a game:"<<"\n";
		cout<<"'cc' ---> computer vs computer"<<"\n";
		cout<<"'pc' ---> player vs computer"<<"\n";
		
		return 0;
	}
	
	//controllo vaidita' input
	if (argv[1][1]!='c' && argv[1][1]!='c' && argv[1][0]!='p'){
		cout<<"Insert a valid string to play a game:"<<"\n";
		cout<<"'cc' ---> computer vs computer"<<"\n";
		cout<<"'pc' ---> player vs computer"<<"\n";
		
		return 0;
	}
	
	Board chessboard;
	
	if (argv[1][1]=='c' && argv[1][0]=='p'){
		cout<<"How to play:"<<"\n";
		cout<<"'A1 B3' to move the piece in A1 to B3"<<"\n";
		cout<<"'XX XX' to see the chessboard and all the pieces"<<"\n";
		
		start_playerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());
	}
	
	return 1;
}


void start_playerVScomputer_game(Board b, int playerColour){
	if (playerColour==0){ //gioca prima il player
	/*
		while (!is_checkmate() && !is_draw()){
			
			player_move();
			
			srand(time(NULL));
			int random_piece = rand()%b.black.size();
			computer_move(b, b.black.at(random_piece));
		}
		/*
		if (is_checkmate()){}
		if (is_draw()){}
		*/
	}
	else{ //gioca prima il computer
	/*
		while (!is_checkmate() && !is_draw()){ -->metodi non ancora scritti, danno undefined reference
			computer_move();
			player_move();
		}
		
		if (is_checkmate()){}
		if (is_draw()){}
		*/
	}
}


// idea: nel vettore di get_moves cerco a caso una mossa e restituisco quella
// input: 	-la board
// 				-il pezzo alla posizione di partenza (condizioni verificate nel main)
// output:	-posizione dove muoviamo il pezzo (estratta a caso)
// 				 o la posizione di partenza se il pezzo non ha mosse
// 
// NON HO TESTATO NULLA
vector<short> computer_move(Board b, const std::shared_ptr<Piece>& piece){
	vector<vector<short>> possible_moves = get_moves(b, piece);
	
	if (possible_moves.size()<=0) {return piece->get_position();}
	
	srand(time(NULL));
	int final_pos = rand()%possible_moves.size();
	
	return possible_moves.at(final_pos);
}

//player_move(Board)
//test:
/*vector<short> ciao = player_move(chessboard);
	while (ciao[0]==-1){
		cout<<"The move is not valid, please insert a correct one!"<<"\n";
		ciao = player_move(chessboard);
	}
*/
vector<short> player_move(Board b){
	vector<short> where = {-1,-1};
	
	string s[2];
	cin>>s[0];
	cin>>s[1];
	
	//controllo input--------
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
	
	vector<short> ciao = {0,0};
	return ciao;
}
#include "Board.cpp" //toglie le undefined references
#include "special_moves.cpp"