#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
	public:
		Player();   	    // Constructor
		~Player();  	    // Destructor;

		void SetNumShips(int ships); // updates number of ships variable

		bool PlaceShip(int size, int row, int col, char direction); // will try to place a ship with upper left point at row, col; returns false if it cant

		void PrintMyShips(); // prints board with players ships
		void PrintEnemyShips(); // prints board with hits/misses of enemy ships
		void ClearBoards(); // returns both boards to original state

		bool CheckHit(int row, int col); // returns true/false if a ship has been hit
		void UpdateEnemyBoard(int row, int col, bool hit); // will update enemy_ships with a hit or miss
	private:
		Board my_ships;
    	Board enemy_ships;
		int numShips;
};


#endif
