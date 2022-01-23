// Margherita Cattapan, 2008798
#include "Board.h"
#include "get_moves.h"
<<<<<<< HEAD
#include "pieces/Space.h"
#include "special_moves.h"

#include <cstdlib>

#include <iostream>
#include <string>
#include <vector>
=======
#include "draw.h"

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

>>>>>>> origin/marghe
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

<<<<<<< HEAD
// methods (besides main)
void start_playerVScomputer_game(Board b, int playerColour);
vector<short> player_move(Board b);
vector<short> computer_move(Board b, const std::shared_ptr<Piece>& piece);

// main
int main(int argc, char* argv[]) { // tutto cio' che ho scritto nel main funziona

    // controllo lunghezza input
    if (argc != 2) {
        cout << "Insert one valid string to play a game:"
             << "\n";
        cout << "'cc' ---> computer vs computer"
             << "\n";
        cout << "'pc' ---> player vs computer"
             << "\n";

        return 0;
    }

    // controllo vaidita' input
    if (argv[1][1] != 'c' && argv[1][1] != 'c' && argv[1][0] != 'p') {
        cout << "Insert a valid string to play a game:"
             << "\n";
        cout << "'cc' ---> computer vs computer"
             << "\n";
        cout << "'pc' ---> player vs computer"
             << "\n";

        return 0;
    }

    Board chessboard;
    // test:
    chessboard.print();
    std::vector<std::vector<short>> movesss = get_moves(chessboard, chessboard.board[1][0]);
    for (int i = 0; i < movesss.size(); i++) {
        std::cout << "( " << movesss[i][0] + 1 << ", " << (char)(movesss[i][1] + 1 + 96) << ")" << std::endl;
    }
    /*
    vector<short> ciao = player_move(chessboard);
    while (ciao[0]==-1){
            cout<<"The move is not valid, please insert a correct one!"<<"\n";
            ciao = player_move(chessboard);
    }
    */
    if (argv[1][1] == 'c' && argv[1][0] == 'p') {
        cout << "How to play:"
             << "\n";
        cout << "'A1 B3' to move the piece in A1 to B3"
             << "\n";
        cout << "'XX XX' to see the chessboard and all the pieces"
             << "\n";
=======
//methods (besides main)
vector<string> playerVScomputer_game(Board b, int playerColour);
vector<string> computerVScomputer_game(Board b, int playerColour);
string player_move(Board& b);
string computer_move(Board& b, const shared_ptr<Piece>& piece);
string converter(int a);

//main
int main (int argc, char*  argv[]){
	
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
			cout<<"'cc' ---> computer vs computer"<<"\n";

			Board chessboard;

			vector<string> game = computerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());

			//request to see the replay
			cout<<"Do you want to see the replay af the all game? s/n ";
			string replay;
			cin>>replay;

			if(replay[0] == 's'){

				cout<<"Enter the name of the file where you want to save the replay:"<<"\n";
				string file;
				cin>>file;
				ofstream log {file};
				if (!log){
					cout<<"can't open output file\n";
				}
				for(int i=0; i<game.size(); i++){
					log<<game[i]<<"\n";
				}
			}

			break;
		}
		case 'p':{
			
			//indirizzamento game player vs computer
			Board chessboard;
			chessboard.print();
			cout<<"How to play:"<<"\n";
			cout<<"Write for example 'A1 B3' to move the piece from A1 to B3"<<"\n";	
			cout<<"Write 'XX XX' to see the chessboard with all the pieces"<<"\n";
			cout<<"ATTENTION: any other string with differnt structure won't be accepted"<<"\n";

			vector<string> game = playerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());

			//request to see the replay
			cout<<"Do you want to see the replay af the all game? s/n ";
			string replay;
			cin>>replay;

			if(replay[0] == 's'){

				cout<<"Enter the name of the file where you want to save the replay:"<<"\n";
				string file;
				cin>>file;
				ofstream log {file};
				if (!log){
					cout<<"can't open output file\n";
				}
				for(int i=0; i<game.size(); i++){
					log<<game[i]<<"\n";
				}
			}

			break;
		}
		default: {
			
			//error message for invalid input
			cout<<"Insert a valid string to play a game:"<<"\n";
			cout<<"'cc' ---> computer vs computer"<<"\n";
			cout<<"'pc' ---> player vs computer"<<"\n";
			break;
		}

	}
	return 0;
	
}
>>>>>>> origin/marghe

        start_playerVScomputer_game(chessboard, chessboard.board[0][0]->get_color());
    }

<<<<<<< HEAD
    return 1;
}

void start_playerVScomputer_game(Board b, int playerColour) {
    if (playerColour == 0) { // gioca prima il player
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
    } else { // gioca prima il computer
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
vector<short> computer_move(Board b, const std::shared_ptr<Piece>& piece) {
    vector<vector<short>> possible_moves = get_moves(b, piece);

    if (possible_moves.size() <= 0) {
        return piece->get_position();
    }

    srand(time(NULL));
    int final_pos = rand() % possible_moves.size();

    return possible_moves.at(final_pos);
}

// player_move(Board)

vector<short> player_move(Board b) {
    vector<vector<shared_ptr<Piece>>> board = b.get_board();

    vector<short> where = {-1, -1};

    string s[2];
    cin >> s[0];
    cin >> s[1];

    // controllo input--------
    // numero di stringhe inserite (boh)
    int dimension = sizeof(s) / sizeof(s[0]);

    if (dimension != 2) {
        cout << "rtvgy"
             << "\n";
        return where;
    }
    // validita'
    if (s[0].length() != 2 || s[1].length() != 2) {
        return where;
    }

    int column1 = tolower(s[0][0]) - 97;
    int row1 = s[0][1] - 49;
    int column2 = tolower(s[1][0]) - 97;
    int row2 = s[1][1] - 49;

    if (column1 < 0 || column2 < 0 || column1 > 7 || column2 > 7) {
        return where;
    }

    if (row1 < 0 || row2 < 0 || row1 > 7 || row2 > 7) {
        return where;
    }

    // muovo il pezzo se e' possibile
    vector<short> initial_pos = {row1, column1};
    vector<short> final_pos = {row2, column2};

    vector<vector<short>> all_moves = get_moves(b, board[row1][column1]);
    for (int i = 0; i < all_moves.size(); i++) {
        if (all_moves[i][0] == row2 && all_moves[i][1] == column2) {
            b.move(initial_pos, final_pos);
            where = final_pos;
        }
    }
    return where;
=======
vector<string> playerVScomputer_game(Board b, int playerColour){
	int i=0;
	bool check;
	if (playerColour==0){ 
		//play the player first
		cout<<"You play first"<<"\n";
		vector<string> move;
		

		while (i<2 || check){
			
			//player move
			string move1 = player_move(b);
			while (move1[0] == '-'){

				move1 = player_move(b);
			}
			move.push_back(move1);
			
			//computer move
			srand(time(NULL));
			int random_piece = rand()%b.black.size();
			string move2 = computer_move(b, b.black.at(random_piece));
			while (move2[0] == '-'){

				srand(time(NULL));
				random_piece = rand()%b.black.size();
				move2 = computer_move(b, b.black.at(random_piece));
			}
			move.push_back(move2);
			
			i++;
		}
		//if (is_checkmate()){}
		//if (is_draw()){}

		return move;
	}
	else{ 
		//play the computer first
		cout<<"Play the computer first"<<"\n";

		vector<string> move;

		while (i<2 || check){
			
			//computer move
			srand(time(NULL));
			int random_piece = rand()%b.white.size();
			string move1 = computer_move(b, b.white.at(random_piece));
			while (move1[0] == '-'){

				srand(time(NULL));
				random_piece = rand()%b.white.size();
				move1 = computer_move(b, b.white.at(random_piece));
			}
			move.push_back(move1);

			//player move
			string move2 = player_move(b);
			while (move2[0] == '-'){

				move2 = player_move(b);
			}
			move.push_back(move2);
			i++;
		}
		
		//if (is_checkmate()){}
		//if (is_draw()){}
		return move;
	}
}

vector<string> computerVScomputer_game(Board b, int playerColour){
	int i=0; //checks if the game has too much moves played (limit-->100+100=200)
	bool check;
	if (playerColour==0){ 
		//computer1 play first

		vector<string> move;

		while (i<50 || check){
			
			//computer1 move
			srand(time(NULL));
			int random_wpiece = rand()%b.white.size();
			string move1 = computer_move(b, b.white.at(random_wpiece));
			while (move1[0] == '-'){

				srand(time(NULL));
				random_wpiece = rand()%b.white.size();
				move1 = computer_move(b, b.white.at(random_wpiece));
			}
			move.push_back(move1);

			//computer2 move
			int random_bpiece = rand()%b.black.size();
			string move2 = computer_move(b, b.black.at(random_bpiece));
			while (move2[0] == '-'){

				srand(time(NULL));
				random_bpiece = rand()%b.black.size();
				move2 = computer_move(b, b.black.at(random_bpiece));
			}
			move.push_back(move2);
			
			i++;
		}
		//if (is_checkmate()){}
		//if (is_draw()){}
		return move;
	}
	else{ 
		//computer2 play first
		vector<string> move;
		while (i<50 || check){
			
			//computer2 move
			srand(time(NULL));
			int random_wpiece = rand()%b.white.size();
			string move1 = computer_move(b, b.white.at(random_wpiece));
			while (move1[0] == '-'){

				srand(time(NULL));
				random_wpiece = rand()%b.white.size();
				move1 = computer_move(b, b.white.at(random_wpiece));
			}
			move.push_back(move1);

			//computer1 move
			int random_bpiece = rand()%b.black.size();
			string move2 = computer_move(b, b.black.at(random_bpiece));
			while (move2[0] == '-'){

				srand(time(NULL));
				random_bpiece = rand()%b.black.size();
				move2 = computer_move(b, b.black.at(random_bpiece));
			}
			move.push_back(move2);

			i++;
		}
		
		//if (is_checkmate()){}
		//if (is_draw()){}
		return move;
	}
}

//computer_move
string computer_move(Board& b, const shared_ptr<Piece>& piece){
	vector<vector<short>> possible_moves = get_moves(b, piece);
	
	string where = "----";

	//check possible moves
	if (possible_moves.size()<=0) {return where;}

	//get initial position
	vector<short> initial_pos = piece->get_position();
	
	//set final position
	srand(time(NULL));
	int final = rand()%possible_moves.size();
	vector<short> final_pos = possible_moves.at(final);

	//move the piece
	b.move(initial_pos, final_pos);

	string i1 = to_string(initial_pos.at(0)+1);
	string i2 = converter(initial_pos.at(1));
	string f1 = to_string(final_pos.at(0)+1);
	string f2 = converter(final_pos.at(1));
	where = i2+i1+ " " +f2+f1;

	return where;
}

//player_move
string player_move(Board& b){
	vector<vector<shared_ptr<Piece>>> board = b.get_board();
	
	string where = "----";

	//acquisition of initial position
	string positions[2];
	string p1 = positions[0];
	string p2 = positions[1];
	cin>>p1;
	cin>>p2;

	//check input
	if (p1.length()!=2 || p2.length()!=2){

		cout<<"Invalid input"<<"\n";
		return where;
	}

	//request chessboard print from the player
	if (tolower(p1[0]) == 'x' && tolower(p1[1]) == 'x' && tolower(p2[0]) == 'x' && tolower(p2[1]) == 'x'){

		b.print();
		return where;
	}

	int column1 = tolower(p1[0])-97;
	int row1 = p1[1]-49;
	int column2 = tolower(p2[0])-97;
	int row2 = p2[1]-49;

	//check validity of row and column
	if (column1<0 || column2<0 || column1>7 || column2>7){return where;}
	
	if (row1<0 || row2<0 || row1>7 || row2>7){return where;}
	
	//chech and move the piece
	vector<short> initial_pos {row1, column1};	
	vector<short> final_pos {row2, column2};
	
	vector<vector<short>> all_moves = get_moves(b, board[row1][column1]);
	for (int i=0; i<all_moves.size(); i++){
		if(all_moves[i][0] == row2 && all_moves[i][1] == column2){
			b.move (initial_pos, final_pos);
			where = p1+ " " +p2;
		}
	}
	
	if (where[0]=='-'){
		cout<<"Please, insert a valid move\n";
	}
	return where;
>>>>>>> origin/marghe
}

string converter(int a){

	switch (a){
		case 0: return "A";
			break;
		case 1: return "B";
			break;
		case 2: return "C";
			break;
		case 3: return "D";
			break;
		case 4: return "E";
			break;
		case 5: return "F";
			break;
		case 6: return "G";
			break;
		case 7: return "H";
			break;
	}
}
//remove undefined references
#include "Board.cpp" 
#include "special_moves.cpp"