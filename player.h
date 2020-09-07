#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player 
{
	public:
		Player();   	    // Constructor
		~Player();  	    // Destructor;

		bool PlaceShip(int size, int row, char c_col, bool horizontal); // will try to place a ship with upper left point at row, col; returns false if it cant 

		void PrintMyShips(); // prints board with players ships
		void PrintEnemyShips(); // prints board with hits/misses of enemy ships
		void ClearBoards(); // returns both boards to original state

		int ConvertCharCoord(char c); //Converts column letter to corresponding int index
		bool CheckHit(); // returns true/false if a ship has been hit

	private:
		Board my_ships;
        Board enemy_ships;
};


#endif
