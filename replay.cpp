#include <string>
#include <vector>

#include <unistd.h>

#include <fstream>
#include <iostream>
using namespace std;

#include "Board.h"

// si esegue il file con:
// 	./replay v logReplay.txt  ----> si vuole l'output a video con il print della scacchiera
// 	./replay f logReplay.txt fileReplay.txt ----> si vuole l'output a file della serie di mosse
int main(int args, char* argv[]){
	
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
		
		Board chessboard;
		chessboard.print();
		string logFile_name = argv[2];
		ifstream in {logFile_name};
		if (!in){
			cout<<"can't open input file "<<logFile_name<<"\n";
			return 0;
		}
			
		string line;
		while (getline(in, line)){
			sleep(2);
			int row1 = line.at(1)-49;
			int column1 = tolower(line.at(0))-97;
			int row2 = line.at(4)-49;
			int column2 = tolower(line.at(3))-97;
			
			vector<short> initial_pos {row1, column1};
			vector<short> final_pos {row2, column2};
			
			chessboard.move(initial_pos, final_pos);
			chessboard.print();
		}
		in.close();
	}
	else{
		if (args!=4){
			cout<<"Invalid input:"<<"\n";
			cout<<"write './replay v [log_file_name] [file_output_replay_name]' to print in the specified file the sequence of the moves"<<"\n";
			return 0;
		}
		
		string logFile_name = argv[2];
		string replayFile_name = argv[3];
		
		ifstream in {logFile_name};
		if (!in){
			cout<<"can't open input file "<<logFile_name<<"\n";
			return 0;
		}
		
		ofstream out {replayFile_name};
		if (!out){
			cout<<"can't open output file "<<logFile_name<<"\n";
			return 0;
		}
		string line;
		while (getline(in, line)){
			out<<line<<"\n";
		}
		in.close();
	}
	
	return 1;
}