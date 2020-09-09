#include "display.h"
#include <iostream>

Display::Display()
{
	m_borderSpace = "\n\n\n--------------------------------------------\n\n\n";
	m_playeriBanner = "                 PLAYER i\n\n\n";
	m_enemyBanner = "      SHOTS FIRED       SHIPS SUNK: i\n\n\n";
	m_colLabel = "      A   B   C   D   E   F   G   H   I\n";
	m_borderLineTop = "    +---+---+---+---+---+---+---+---+---+\n";
	m_rowiLabel = "  i |   |   |   |   |   |   |   |   |   |\n";
	m_gridLine = "    +---+---+---+---+---+---+---+---+---|\n";
	m_borderLineBottom = "    +-----------------------------------+";
	m_friendlyBanner = "\n\n\n\n                YOUR SHIPS\n\n\n";
}

void Display::genericBoard() const
{
	std::cout << m_colLabel;
	std::cout << m_borderLineTop;
	std::string rowiLabel = m_rowiLabel;

	for(int i = 1; i <= 9; i++)
	{
		rowiLabel.replace(2, 1, std::to_string(i));
		std::cout << rowiLabel;

		if(i < 9)
		{
			std::cout << m_gridLine;
		}
		else
		{
			std::cout << m_borderLineBottom;
		}
	}
}

void Display::genericFrame() const
{
	std::cout << m_borderSpace;
	std::cout << m_playeriBanner;
	std::cout << m_enemyBanner;
	genericBoard();
	std::cout << m_friendlyBanner;
	genericBoard();
	std::cout << m_borderSpace;
}

void Display::enemyBoard(char** board, int playerID, int shipsSunk) const
{
	std::string playeriBanner = m_playeriBanner;
	std::string enemyBanner = m_enemyBanner;
	std::string rowiLabel = m_rowiLabel;

	playeriBanner.replace(24, 1, std::to_string(playerID));
	enemyBanner.replace(36, 1, std::to_string(shipsSunk));

	std::cout << m_borderSpace;
	std::cout << playeriBanner;
	std::cout << enemyBanner;
	std::cout << m_colLabel;
	std::cout << m_borderLineTop;
	
	for(int i = 0; i < 9; i++)
	{
		rowiLabel.replace(2, 1, std::to_string(i+1));

		for(int j = 0; j < 9; j++)
		{
			if(board[i][j] == 'X')
			{
				rowiLabel.replace(4*j+6, 1, std::string(1, board[i][j]));
			}
			else if(board[i][j] == 'O')
			{
				rowiLabel.replace(4*j+6, 1, std::string(1, board[i][j]));
			}
		}

		std::cout << rowiLabel;
		rowiLabel = m_rowiLabel;

		if(i < 8)
		{
			std::cout << m_gridLine;
		}
		else
		{
			std::cout << m_borderLineBottom;
		}
	}
}

char** Display::test_enemyBoard()
{
	//initialize board
	char** board = new char*[9];
	for(int i = 0; i < 9; i++)
	{
		board[i] = new char[9];
		for(int j = 0; j < 9; j++)
		{
			board[i][j] = ' ';
		}
	}

	board[0][5] = 'O';
	board[0][8] = 'X';
	board[1][8] = 'X';
	board[2][1] = 'X';
	board[2][2] = 'X';
	board[2][3] = 'X';
	board[3][3] = 'O';
	board[4][1] = 'X';
	board[4][6] = 'X';
	board[4][8] = 'X';
	board[5][6] = 'X';
	board[6][3] = 'O';
	board[6][6] = 'X';
	board[7][6] = 'X';
	board[8][0] = 'X';
	board[8][1] = 'X';
	board[8][2] = 'O';

	return board;
}
