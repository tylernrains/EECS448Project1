/*------------------------------------------------------------
 * @Filename: display.h
 * @Description: pretty prints game elements
 ------------------------------------------------------------*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display
{
	private:
	//board elements
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

	/**
	 * @pre: board must use 'X' and 'O' to denote hits and misses, respectively.
	 * @post: prints state of enemy board
	 * @param: board, 9x9 array marked with 'X's and/or 'O's, 
	 * playerID: either 1 or 2 (to differentiate players)
	 **/
	//display state of enemy board
	void enemyBoard(char board[][9], int playerID) const;

	public:

	/**
	 * @post: constructs display obj.
	 **/
	Display();

	/**
	 * @pre: none
	 * @post: none
	 **/
	~Display();

	/**
	 * @pre: board must use 'X' and 'S' to denote hits and ships, respectively.
	 * @post: prints state of player's ships
	 * @param: board, 9x9 array marked with 'X's and/or 'S's
	 **/
	//in-game visual elements
	void friendlyBoard(char board[][9]) const;

	/**
	 * @pre: boards must use 'X's, 'O's, and 'S's to denote hits, misses, and ships, respectively
	 * @post: prints state of playerID's enemy board and their ships
	 * @param: playerID, either 1 or 2 (to differentiate players), enemyBrd: 9x9 array marked with 'X's and/or 'O's, 
	   friendlyBrd: 9x9 array marked with 'X's and/or 'S's
	 **/
	void matchFrame(int playerID, char enemyBrd[][9], char friendlyBrd[][9]) const;

	/**
	 * @post: prints hit message
	 **/
	void hit() const;

	/**
	 * @post: prints miss message
	 **/
	void miss() const;
};
#endif
