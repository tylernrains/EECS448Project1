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

	//shot feed-back elements
	std::string m_hit0;
	std::string m_hit1;
	std::string m_hit2;
	std::string m_hit3;
	std::string m_hit4;
	std::string m_hit5;
	std::string m_miss;

	void genericBoard() const;
	void genericFrame() const;
	void enemyBoard(char** board, int playerID, int shipsSunk) const;


	public:
	Display();
	char** test_enemyBoard();
	char** test_friendlyBoard();
	void friendlyBoard(char** board) const;
	void matchFrame(int playerID, int shipsSunk, char** enemyBrd, char** friendlyBrd) const;
	void hit() const;
	void miss() const;

};
#endif
