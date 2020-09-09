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
		void updateBoard(int row, int col, char c); // Function to update board
		char getValue(int row, int col); // gets value at coordinates
		char getBoard() const;

	private:
		int numRows = 9;      // Numbers (1-9)
		int numCols = 9;      // Letters (A-I)
		char m_board[9][9];  
};


#endif
