#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <board.h>
using namespace std;

class Player 
{
	public:
		Player();   	    // Constructor
		~Player();  	    // Destructor;

	private:
		Board my_ships;
        Board enemy_ships;
};


#endif
