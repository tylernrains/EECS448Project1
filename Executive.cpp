#include "Executive.h"
#include "player.h"
#include "display.h"
#include <iostream>
using namespace std;

int Executive::charToInt(char c) {return (toupper(c) - 65);}

void Executive::run()
{
	int shipnum = 0;
	
	Display display;
	Player player1;
	Player player2;
	int row, col;
	char c_col; // char version of the column

	chooseShipNum1:
		cout << "How many ships do you want to place in the grid? (choose from 1 to 5)\n";
		cin >> shipnum;
		player1.SetNumShips(shipnum); //decalers number of ships for both players
	
		
		if (shipnum < 1 || shipnum > 5)
		{
			cout << "Invaild number of ships!\n";
			goto chooseShipNum1;
		}

		for (int i = 1; i <= shipnum; i++)
		{
			chooseShipPosition1:
				
				//player1.PrintMyShips(); //blank Board
				display.friendlyBoard(player1.my_ships.m_board);
				char direction = 'u'; //default direction is up

				if (i == 1)
				{
					cout << "Player1, Where do you want to place 1X" << i << " on the grid? ((row(1-9) col(A-I)): ";
					cin >> row >> c_col;
				}
				else
				{
					cout << "Choose a pivot coordinate for 1X" << i << " ship on the grid ((row(1-9) col(A-I)): "; 
					cin >> row >> c_col;
					cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
					cin >> direction;
				}
				col = charToInt(c_col); // convert char to int
				row--; // decrement row by 1 for indexing array
				direction = toupper(direction); 
		
				if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R') 
				{
					cout << "Invalid direction input!\n";
					goto chooseShipPosition1;
				}
				if (!player1.PlaceShip(i, row, col, direction))
				{
					cout << "ship could not be placed there. \n";
					goto chooseShipPosition1;
				}
		}

		//player1.PrintMyShips(); //  print last time so player can see 1x5 ship placed	
		display.friendlyBoard(player1.my_ships.m_board);

		cout << " Now switch to Player2\n \n \n \n \n";
		player2.SetNumShips(shipnum);

		for (int i = 1; i <= shipnum; i++)
		{
			chooseShipPosition2:

				//player2.PrintMyShips();
				display.friendlyBoard(player2.my_ships.m_board);
				char direction = 'u';

				if (i == 1)
				{
					cout << "Player 2, Where do you want to place 1X" << i << " on the grid? ((row(1-9) col(A-I)): ";
					cin >> row >> c_col;
					col = charToInt(c_col);
				}
				else
				{
					cout << "Choose a pivot coordinate for 1X" << i << " ship on the grid ((row(1-9) col(A-I)): "; 
					cin >> row >> c_col;
					cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
					cin >> direction;
				}
				col = charToInt(c_col);
				row--;
				direction = toupper(direction);
		
				if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R') 
				{
					cout << "Invalid direction input!\n";
					goto chooseShipPosition2;
				}
				if (!player2.PlaceShip(i, row, col, direction))
				{
					cout << "ship could not be placed there. \n";
					goto chooseShipPosition2;
				}
		}
		//player2.PrintMyShips();
		display.friendlyBoard(player2.my_ships.m_board);
	

		cout << " Now play the battle ship\n";

		bool winner = false;
		int p1Sunk = 0;
		int p2Sunk = 0;
		int round = 1;

		while (!winner)
		{
			if (round % 2 == 1)
			{
				cout << "Player 1's turn!\n";
				//player1.PrintEnemyShips();
				display.matchFrame(1, p1Sunk, player1.enemy_ships.m_board, player1.my_ships.m_board);
				cout << "\n \n";
				cout << "Your Ships \n";
				//player1.PrintMyShips();		//Print 2 board before fire
				//display.friendlyBoard(player1.my_ships.m_board);

				cout << "Choose the coordinate that you want to fire : ((row(1 - 9) col(A - I))\n";
				cin >> row >> c_col;
				col = charToInt(c_col);
				row --;

				if (player2.CheckHit(row, col))
				{
					//cout << "HIT!\n";
					display.hit();
					player1.UpdateEnemyBoard(row, col, true);
				}
				else
				{
					//cout << "MISS!\n";
					display.miss();
					player1.UpdateEnemyBoard(row, col, false);
				}
			}
			else
			{
				cout << "Player 2's turn!\n";
				//player2.PrintEnemyShips();
				display.matchFrame(2, p2Sunk, player2.enemy_ships.m_board, player2.my_ships.m_board);
				cout << "\n \n";
				cout << "Your Ships \n";
				//player2.PrintMyShips();		//Print 2 board before fire
				//display.friendlyBoard(player2.my_ships.m_board);
			
				cout << "Choose the coordinate that you want to fire : ((row(1 - 9) col(A - I))\n";
				cin >> row >> c_col;
				col = charToInt(c_col);
				row --;

				if (player1.CheckHit(row, col))
				{
					//cout << "HIT!\n";
					display.hit();
					player2.UpdateEnemyBoard(row, col, true);
				}
				else
				{
					//cout << "MISS!\n";
					display.miss();
					player2.UpdateEnemyBoard(row, col, false);
				}
			}

			round++;
	/*
			if (numofhit1 == myplayer2.getShipnum())
			{
				cout << "Player1 Wins!\n";
				winner = true;
			}

			else ( numofhit2 == player1.getShipnum())
			{
				cout << "Player2 Wins!\n";
				winner = true;
			}
	*/
		}

}
