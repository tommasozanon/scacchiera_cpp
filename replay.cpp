#include "Board.h"
#include "pieces/Piece.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

// si esegue il file con:
// 	./replay v logReplay.txt  ----> si vuole l'output a video con il print della scacchiera
// 	./replay f logReplay.txt fileReplay.txt ----> si vuole l'output a file della serie di mosse
int main(int args, char* argv[]){
	//argv[1] = f oppure v
	//argv[2] = log
	//argv[3] esiste solo se (argv[1]=f) e = file replay
	
	if (args<=2){
		cout<<"Invalid input:"<<"\n";
		cout<<"write './replay v [log_file_name]' to see the board and the sequence of the moves"<<"\n";
		cout<<"write './replay f [log_file_name] [file_output_replay_name]' to print in the specified file the sequence of the moves"<<"\n";
	
		return 0;
	}
	
	string InputString1 = argv[1];
	
	if (InputString1!="v" && InputString1!="f"){
		cout<<"Invalid input: insert 'v' or 'f' as first string in the command line"<<"\n";
		
		return 0;
	}
	
	if (InputString1=="v"){
		if (args!=3){
			cout<<"Invalid input:"<<"\n";
			cout<<"write './replay v [log_file_name]' to see the board and the sequence of the moves"<<"\n";
			return 0;
		}
	}
	else{
		if (args!=4){
			cout<<"Invalid input:"<<"\n";
			cout<<"write './replay v [log_file_name] [file_output_replay_name]' to print in the specified file the sequence of the moves"<<"\n";
			return 0;
		}
	}
	
	
	return 1;
}

#include "Board.cpp"