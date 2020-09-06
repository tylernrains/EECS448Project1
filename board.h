#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board 
{
	public:
		Board();   	    // Constructor
		~Board();  	    // Destructor
		void printBoard();  // Print board
		void updateBoard(); // Function to update board
	private:
		int numRows = 9;
		int numCols = 9;
		char** board;



};


#endif
