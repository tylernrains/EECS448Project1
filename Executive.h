#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Board.h"
#include "Player.h"

#include <iostream>
using namespace std;

class Executive
{
public:

	Executive(){};
	~Executive(){};
	void run();
	int charToInt(char c);
	bool validColumn(char c); // Function for verifying user input

};
#endif // EXECUTIVE_H

