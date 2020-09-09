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
