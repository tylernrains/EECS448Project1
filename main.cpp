#include <iostream>
#include <string>
#include "Executive.h"

int main(){
	/*
	cout << "Battleship Game\n";
	/*Board board1;
	int numHits = 0;
	*/

  /*
	Display display;
	//display.genericFrame();
	char** enemyBoard = display.test_enemyBoard();
	char** friendlyBoard = display.test_friendlyBoard();

	//display.enemyBoard(enemyBoard, 1, 3);
	//display.friendlyBoard(friendlyBoard);
	display.matchFrame(2, 3, enemyBoard, friendlyBoard);
	display.hit();
	display.miss();
  */
 	// Board board1;
	// int numHits;
	
	// board1.printBoard();
	// while(numHits < 3)
	// {
	// 	cout << "Enter coordinates to hit: ";
	// 	char row;
	// 	int col;
	// 	cin >> row >> col;
	// 	board1.updateBoard(row, col, 'c');
	// 	board1.printBoard();
	// 	numHits++;
	// }
	

	Executive exec;
	exec.run();

	return(0);
}
