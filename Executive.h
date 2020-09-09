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
	void run();
	int charToInt(char c);

};
#endif // EXECUTIVE_H

