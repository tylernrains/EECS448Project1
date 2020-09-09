#include "Executive.h"
#include <iostream>
#include <string>
using namespace std;

void run()
{
	int shipnum = 0;
	int playerrows = 0;	
	char playercols = ' ';
	string direction = " ";

	Board player1board;
	Board enemy1board;
	Board player2board;
	Board enemy2board;

	Player myplayer1;
	Player myplayer2;

	cout << " Battleship Game!\n";

	//need to display two blank Board 
	//player1board.printBoard();
	//player2board.printBoard();

	chooseShipNum1:
		cout << "Player1, How many ships do you want to place in the grid? (choose from 1 to 5)\n";
		cin >> shipnum;
		myplayer1.setShipnum(shipnum);
	
		
		if (shipnum < 1 || shipnum > 5)
		{
			cout << "Invaild number of ships!\n";
			goto chooseShipNum1;
		}

		for (i = 1; i <= shipnum; i++)
		{
			chooseShipPosition1:
				
				player1board.PrintBoard(); //blank Board
				enemy1board.PrintBoard(); //blank Board

				cout << "Player1, Where do you want to place 1X"<<i<<" on the grid? ((row(1-9) col(A-I))\n";
				cin >> playerrows >> playercols;
				cout << "And which direction?(up, right, down, or left)";
				cin >> direction;

				myplayer1.PlaceShip(i, playerrows, playercols, direction); //check the position if vaild

				if (myplayer1.PlaceShip(i, playerrows, playercols, direction))
				{
					player1board.updateBoard();   //place some ships in own board
					myplayer1.PrintMyShip();	
					myplayer1.PrintEnemyShip();
				}

				else if (!myplayer1.PlaceShip(i, playerrows, playercols, direction))
				{
					cout << "Invaild Position!\n ";
					goto chooseShipPosition1;
				}
		}	

		cout << " Now switch to the Player2\n ";

		chooseShipNum2:
		cout << "Player2, How many ships do you want to place in the grid? (choose from 1 to 5)\n";
		cin >> shipnum;
		myplayer2.setShipnum(shipnum);


		if (shipnum < 1 || shipnum > 5)
		{
			cout << "Invaild number of ships!\n";
			goto chooseShipNum2;
		}

		for (i = 1; i <= shipnum; i++)
		{

		chooseShipPosition2:

				player2board.PrintBoard(); //blank Board
				enemy2board.PrintBoard(); //blank Board

				cout << "Player2, Where do you want to place 1X" << i << " on the grid? ((row(1-9) col(A-I))\n";
				cin >> playerrows >> playercols;
				cout << "And which direction?(up, right, down, or left)";
				cin >> direction;

				myplayer2.PlaceShip(i, playerrows, playercols, direction); //check the position if vaild

				if (myplayer2.PlaceShip(i, playerrows, playercols, direction))
				{
					player2board.updateBoard();   //place some ships in own board
					myplayer2.PrintMyShip();
					myplayer2.PrintEnemyShip();
				}

				else if (!myplayer2.PlaceShip(i, playerrows, playercols, direction))
				{
					cout << "Invaild Position!\n ";
					goto chooseShipPosition2;
				}
		}

		cout << " Now play the battle ship\n";

		/*string playername = "";
		int shipnum = 0;
		int playerrows = 0;
		char playercols = '';

		Board player1board;
		Board enemy1board;
		Board player2board;
		Board enemy2board;

		Player myplayer1;
		Player myplayer2;*/

		bool winner = false;
		int numofhit1 = 0;
		int numofhit2 = 0;
		int rounds = 1;

		while (!winner)
		{
			if (rounds % 2 = 1)
			{
				myplayer1.PrintMyShip();		//Print 2 board before fire
				myplayer1.PrintEnemyShip();

				cout << " Player1's round, Now hit: " << numofhit1 << '\n';
				cout << " please choose the coordinate that you want to fire : ((row(1 - 9) col(A - I))\n";
				cin >> playerrows >> playercols;

				enemy1board.updateBoard();		//update enemy1board after player1 fire(change player1 view)
				//myplayer1.updateEnemyShip(playerrows, playercols); 

				myplayer1.PrintMyShip();		//My ship1 print same(player1 view)
				myplayer1.PrintEnemyShip();		//Enemy Ship1 print change(player1 view)

				if (myplayer1.checkHit(playerrows, playercols))
				{
					numofhit1++;
				}

				player2board.updateBoard();		//update player1ship after player1 fire(player2 view will change in next round)
				//myplayer2.updateMyship(playerrows, playercols);
			}

			else if (rounds % 2 = 0);
			{
				myplayer2.PrintMyShip();
				myplayer2.PrintEnemyShip();

				cout << " Player2's round, Now hit: " << numofhit2 << '\n';
				cout << " please choose the coordinate that you want to fire : ((row(1 - 9) col(A - I))\n";
				cin >> playerrows >> playercols;


				enemy2board.updateBoard();		//update enemy1board after player2 fire(player2 view change)

				//myplayer2.updateEnemyShip(playerrows, playercols); 

				myplayer2.PrintMyShip();		//My ship2 print same(player2 view)
				myplayer2.PrintEnemyShip();		//Enemy Ship2 print change(player2 view)

				if (myplayer2.checkHit(playerrows, playercols))
				{
					numofhit2++;
				}

				player1board.updateBoard();		//update player1ship after player2 fire(player1 view will change in next round)
				//myplayer2.updateMyship(playerrows, playercols);
			}

			rounds++;

			if (numofhit1 == myplayer2.getShipnum())
			{
				cout << "Player1 Wins!\n";
				winner = true;
			}

			else ( numofhit2 == myplayer1.getShipnum())
			{
				cout << "Player2 Wins!\n";
				winner = true;
			}

		}

}