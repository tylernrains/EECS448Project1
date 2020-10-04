#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "board.h"
#include "player.h"
#include "AI.h"
#include "display.h"
#include "Ship.h"

#include <time.h>
#include <iostream>
using namespace std;

class Executive
{
public:

	/**
	 * Constructor for Executive.
	 * @post Executive is initialized.
	 */
	Executive(){};

	/**
	 * Destructor for Executive.
	 * @post Executive is destroyed.
	 */
	~Executive(){};

	// Setup and runtime vars.
	Player player1;
	Player player2;
	AI computer;
	Ship shipofplayer1;
	Ship shipofplayer2;
	Ship shipofai;
	Display display;
	int row, col;
	char c_col;
	int shipnum = 0;


	/**
 	* @pre:	None
 	* @post: function to hide player info when switch player1 to 2 or player2 to 1
 	* @param: print 50 blank line when need to switch player
 	**/
	void WaitEnter();


	/**
 	* @post: run the program
	* @param: Setup Player vs Player Battleship game, the prog gets ship info from players
	* 		  then gives Executive control to run_PvP();
 	**/
	void run_setup_PvP();


	/**
 	* @post: run the program
	* @param: Setup Player vs AI Battleship game, the prog gets ship info from player
	* 		  then gives Executive control to run_PvAi();
 	**/
	void run_setup_PvAi();


	/**
 	* @post: run the program
	* @param: play the Battleship game, players will fire at the enemy ships until there
	* 		  is a winner
 	**/
	void run_PvP();


	/**
 	* @post: run the program
	* @param: play the Battleship game, players will fire at the AI ships until there
	* 		  is a winner
 	**/
	void run_PvAi();


	/**
 	* @pre: input the correct char type
 	* @post: convert letters to corresponding numbers
	* @param: get the letter from the player, then use the formula to convert letter to numbers
	* @return: return ((toupper(c) - 65))
 	**/
	int charToInt(char c);

	/**
 	* @pre: input the correct char type
 	* @post: verifying user input if it's within the range of A-I
	* @param: get the letter from the player, then check the range
	* @return: return true when the letter is within the range of A-I
 	**/
	bool validColumn(char c);

	/**
 	* @pre: input the correct int type
 	* @post: add the number of grids occupied by all ships
	* @param: get the ship number from the player, then calculate the number of grids occupied by the ship
	* @return: return n, the number of grids occupied by all ships
 	**/
  	int numShipCoords(int shipNum);

	/**
	 * Fires a torpedo.
	 * @param direction - a letter indicating the direction of travel for the torpedo
	 * @param fireposition - the row or column to fire at
	 * @param iscol - indicates whether the target is a row or column
	 * @param friendly - the Player who is firing the torpedo
	 * @param enemy - the Player opposing friendly
	 * @param enemyShip - the Ship associated with enemy
	 * @post torpedo has been fired to specifications.
	 */
	void firetorpedo(string direction, int firepostion, bool iscol, Player& friendly, Player& enemy, Ship& enemyShip);

};
#endif // EXECUTIVE_H
