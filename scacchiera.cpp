#include "Board.h"
#include "special_moves.h"
#include "get_moves.h"
#include "special_moves.h"

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
int main (int argc, char*  argv[]){ // tutto cio' che ho scritto nel main funziona (ci mancherebbe)
	
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
	return 1;
}

// idea: nel vettore di get_moves cerco a caso una mossa e restituisco quella
// input: 	-la board
// 				-il pezzo alla posizione di partenza (condizioni verificate nel main)
// output:	-posizione dove muoviamo il pezzo (estratta a caso)
// 				 o la posizione di partenza se il pezzo non ha mosse
// 
// NON HO TESTATO NULLA (da' undefined reference, ma e' tardi e mi sto addormentando)
vector<short> computer_move(Board b, const std::shared_ptr<Piece>& piece){
	vector<vector<short>> possible_moves = get_moves(b, piece);
	
	if (possible_moves.size()<=0) {return piece->get_position();}
	
	srand(time(NULL));
	int final_pos = rand()%possible_moves.size();
	
	return possible_moves.at(final_pos);
}