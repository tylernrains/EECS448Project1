#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display
{
	private:
	std::string m_borderSpace;
	std::string m_playeriBanner;
	std::string m_enemyBanner;
	std::string m_colLabel;
	std::string m_borderLineTop;
	std::string m_rowiLabel;
	std::string m_gridLine;
	std::string m_borderLineBottom;
	std::string m_friendlyBanner;

	public:
	Display();
	void genericBoard() const;
	void genericFrame() const;
	void enemyBoard(char** board, int playerID, int shipsSunk) const;
	void friendlyBoard(char** board) const;

	char** test_enemyBoard();
	char** test_friendlyBoard();
};
#endif
