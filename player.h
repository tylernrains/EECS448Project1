#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player 
{
	public:
		Player();   	    // Constructor
		~Player();  	    // Destructor;

		void printMyShips();
		void printEnemyShips();
		void clearBoards();

		bool checkHit();

	private:
		Board my_ships;
        Board enemy_ships;
};


#endif
