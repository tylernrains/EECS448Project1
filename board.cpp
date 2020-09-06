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
	for(int i=0; i<numRows; i++)
	{	
		for(int j=0; j<numCols; j++)
		{
			if(i == 0 && j == 0)
			{
				cout << "  ";
				for(char l = 'A'; l <= 'I'; l++)
				{
					cout << l << " ";
				}
				cout << "\n";
			}
			if(j == 0)
			{
				cout << i+1 << " ";
			}
			cout << m_board[i][j] << " ";
		}
		cout << "\n";
	}
}

void Board::updateBoard() 
{}


