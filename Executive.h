#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "board.h"
#include "player.h"

#include <iostream>
using namespace std;

class Executive
{
public:

	Executive(){};
	~Executive(){};
	void WaitEnter();
	void run();
	int charToInt(char c);
	bool validColumn(char c); // Function for verifying user input

};
#endif // EXECUTIVE_H

