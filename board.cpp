#include "Board.h"

Board::Board()
{
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			m_board[i][j] = '-';
		}
	}
}

Board::~Board()
{

}

void Board::printBoard()
{
	char sideLetter = 'A';
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			if(i == 0 && j == 0)
			{
				cout << "  ";
				for(int l = 1; l <= 9; l++)
				{
					cout << l << " ";
				}
				cout << "\n";
			}
			if(j == 0)
			{
				cout << sideLetter << " ";
			}
			cout << m_board[i][j] << " ";
		}
		sideLetter++;
		cout << "\n";
	}
}

void Board::updateBoard(char row, int col) 
{
	int numberRow;
	switch(row) // switch to change char to an int to update board
	{
		case 'A':
		case 'a':
			numberRow = 0;
			break;
		case 'B':
		case 'b':
			numberRow = 1;
			break;
		case 'C':
		case 'c':
			numberRow = 2;
			break;
		case 'D':
		case 'd': 
			numberRow = 3;
			break;
		case 'E':
		case 'e':
			numberRow = 4;
			break;
		case 'F':
		case 'f':
			numberRow = 5;
			break;
		case 'G':
		case 'g':
			numberRow = 6;
			break;
		case 'H':
		case 'h':
			numberRow = 7;
			break;
		case 'I':
		case 'i':
			numberRow = 8;
			break;
		default:
			cout << "Invalid Coordinate! Re-Enter A-I!";
	}

	cout << numberRow << col << "\n";	

	m_board[numberRow][col-1] = 'X';
}








