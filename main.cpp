#include <iostream>
#include <string>
#include "Executive.h"

int main(){
	cout << "Battleship Game\n";
	/*Board board1;
	int numHits = 0;
	board1.printBoard();
	while(numHits < 3)
	{
		cout << "Enter coordinates to hit: ";
		char row;
		int col;
		cin >> row >> col;
		board1.updateBoard(row, col);
		board1.printBoard();
		numHits++;
	}
	*/
	Executive exec;
	exec.run();

	return(0);
}
