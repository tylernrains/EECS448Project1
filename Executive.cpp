
#include "Executive.h"
#include "player.h"
#include "display.h"
#include "Ship.h"
#include <iostream>
using namespace std;

int Executive::charToInt(char c) {return ((toupper(c) - 65));}

int Executive::numShipCoords(int shipNum)
{
	int n = 0;

	for(int i = 1; i <= shipNum; i++)
	{
		n = n+i;
	}

	return n;
}

void Executive::WaitEnter()
{
	cin.ignore();
	cout << "Press ENTER to end turn...";
	cin.get();
	for (int i = 0; i <= 50; i++) cout << endl;
}

bool Executive::validColumn(char c)
{
	if (!isalpha(c) || (toupper(c) < 65 || toupper(c) > 73))
	{
		cout << "Invalid input! Column must be A-I!: ";
		return false;
	}
	else
	{
		return true;
	}
}

void Executive::run_setup_PvP()
{


	cout << "How many ships do you want to place in the grid (choose from 1 to 5)? ";
	cin >> shipnum;
	player1.SetNumShips(shipnum); //decalers number of ships for both players
	shipofplayer1.setShipNumber(numShipCoords(shipnum));


	if (shipnum < 1 || shipnum > 5)
	{
		while (!(cin >> shipnum))
		{
			cout << "Invalid! Must be 1-5!: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
		//cout << "Invaild number of ships!\n";
		//goto chooseShipNum1;
	}

	for (int i = 1; i <= shipnum; i++)
	{
		chooseShipPosition1:

			//blank Board
			display.friendlyBoard(player1.my_ships.m_board);
			char direction = 'u'; //default direction is up

			if (i == 1)
			{
				cout << "\nPlayer 1, Where do you want to place 1X" << i << " on the grid (row(1-9) col(A-I))? ";
				while(!(cin >> row)||row < 1 || row > 9)
				{
					cout << "Invalid input! Row must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout << "Now enter a column A-I: ";
				cin >> c_col;
				cout << "\n";
				while(!validColumn(c_col))
				{
					cin >> c_col;
				}
				col = charToInt(c_col);
			}
			else
			{
				cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-9) col(A-I)): ";
				while (!(cin >> row)||row < 1 || row > 9)
				{
					cout << "Invalid input! Row must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout << "Now enter a column A-I: ";
				cin >> c_col;
				while (!validColumn(c_col))
				{
					cin >> c_col;
				}

			chooseShipDirection1:
				cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
				cin >> direction;
			}
			col = charToInt(c_col); // convert char to int
			row--; // decrement row by 1 for indexing array
			direction = toupper(direction);

			if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
			{
				cout << "Invalid direction input!\n";
				goto chooseShipDirection1;
			}
			if (!player1.PlaceShip(i, row, col, direction))
			{
				cout << "Ship could not be placed there. \n";
				goto chooseShipPosition1;
			}
	}

	//print last time so player can see 1x5 ship placed
	display.friendlyBoard(player1.my_ships.m_board);

	cout <<" Switch to Player 2 Setting!\n";
	WaitEnter();

	//cout << "Player 2, how many ships do you want to place in the grid (choose from 1 to 5)? ";
	//cin >> shipnum;
	player2.SetNumShips(shipnum);
	shipofplayer2.setShipNumber(numShipCoords(shipnum));

	for (int i = 1; i <= shipnum; i++)
	{
		chooseShipPosition2:

			display.friendlyBoard(player2.my_ships.m_board);
			char direction = 'u';

			if (i == 1)
			{
				cout << "\nPlayer 2, Where do you want to place 1X" << i << " on the grid (row(1-9) col(A-I))? ";
				while (!(cin >> row)||row < 1 || row > 9)
				{
					cout << "Invalid input! Row must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout << "Now enter a column A-I: ";
				cin >> c_col;
				cout << "\n";
				while (!validColumn(c_col))
				{
					cin >> c_col;
				}
				col = charToInt(c_col);
			}
			else
			{
				cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-9) col(A-I)): ";
				while (!(cin >> row)||row < 1 || row > 9)
				{
					cout << "Invalid input! Row must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cout << "Now enter a column A-I: ";
				cin >> c_col;
				while (!validColumn(c_col))
				{
					cin >> c_col;
				}
			chooseShipDirection2:
				cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
				cin >> direction;
			}
			col = charToInt(c_col);
			row--;
			direction = toupper(direction);

			if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
			{
				cout << "Invalid direction input!\n";
				goto chooseShipDirection2;
			}
			if (!player2.PlaceShip(i, row, col, direction))
			{
				cout << "Ship could not be placed there. \n";
				goto chooseShipPosition2;
			}
	}

	display.friendlyBoard(player2.my_ships.m_board);
	WaitEnter();

	run_PvP();

}



	void Executive::run_setup_PvAi(){

	// ##########################################################################
	// ##########################################################################
	//
	//
	//		Enter code here to setup player 1 and AI ships
	//
	//
	// ##########################################################################
	// ##########################################################################


	std::cout << "\n\nThis is running the setup for PvAi\n\n";

	run_PvAi();


	}





	void Executive::run_PvP() {

	cout << "\nNow play battleship!\n";

	int round = 1;
	bool player1torpedo = true;
	bool player2torpedo = true;
	string playershot = "";

	while (!shipofplayer1.isSunk() || !shipofplayer2.isSunk())
	{
		if (round % 2 == 1)
		{
			cout << "Player 1's turn!\n";
			cout << "You have been hit " << shipofplayer1.getHit() << " times\n";
			//Print boards before fire
			display.matchFrame(1, player1.enemy_ships.m_board, player1.my_ships.m_board);

			cout << "\nDo you want to fie a torpedo or a regular shot?";
			cout << "\nEnter torp for the torpedo and shot for the regular shot: ";

			cin >> playershot;

			if (playershot == "torp" || playershot == "Torp")
			{
				string colorrow = "";
				cout << "\nEnter col to shoot from a column and row to shoot from a row";
				cin >> colorrow;
				while(colorrow == "row" || colorrow == "row" || colorrow == "col" || colorrow == "Col")
				{
					if (colorrow == "row" || colorrow == "row")
					{
						cout << "\nchoose a row between 1 and 9 ";
						while (!(cin >> row) || row < 1 || row > 9)
						{
							cout << "Invalid! Must be 1-9!: ";
							cin.clear();
							cin.ignore(123, '\n');
						}
						row --;
						firetorpedo(round, row, false);
					}
					else if (colorrow == "col" || colorrow == "Col")
					{
						cout << "\nchoose a Column between A and I ";
						cin >> c_col;
						while (!validColumn(c_col))
						{
							cin >> c_col;
						}
						col = charToInt(c_col);
						firetorpedo(round, col, true);
					}
					else {
						cout << "Invalid! Enter row or col: ";
						cin >> colorrow;
					}
				}
			}
			else if(playershot == "shot" || playershot == "Shot")
			{
				chooseFire1:
				cout << "\nChoose the coordinate that you want to fire (row(1 - 9) col(A - I)): ";
				while (!(cin >> row) || row < 1 || row > 9)
				{
					// cout <<"row = "<<row<<'\n';
					cout << "Invalid! Must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin >> c_col;
				while (!validColumn(c_col))
				{
					cin >> c_col;
				}
				col = charToInt(c_col);
				row --;


				if (player2.CheckHit(row, col))
				{
					display.hit();
					shipofplayer2.setHit();
					player1.UpdateEnemyBoard(row, col, true);
					if (shipofplayer2.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
				}

				else if(player2.my_ships.getValue(row, col) == 'X')
				{
					//cout <<player2.my_ships.getValue(row, col);
					cout << "\n\nYou've already hit that spot!\n";
					goto chooseFire1;
				}
				else if(player1.enemy_ships.getValue(row, col) == 'O')
				{
					cout <<"\n\nYou've already fire this point!\n";
					goto chooseFire1;
				}
				else
				{
					display.miss();
					player1.UpdateEnemyBoard(row, col, false);
					player2.my_ships.updateBoard(row, col, 'O');
				}
			}
		}
		else
		{
			cout << "Player 2's turn!\n";
			cout << "You have been hit " << shipofplayer2.getHit() << " times\n";
			//Print boards before fire
			display.matchFrame(2, player2.enemy_ships.m_board, player2.my_ships.m_board);

			cout << "\nDo you want to fie a torpedo or a regular shot?";
			cout << "\nEnter torp for the torpedo and shot for the regular shot: ";

			cin >> playershot;

			if (playershot == "torp" || playershot == "Torp")
			{
				string colorrow = "";
				cout << "\nEnter col to shoot from a column and row to shoot from a row";
				cin >> colorrow;
				while(colorrow == "row" || colorrow == "row" || colorrow == "col" || colorrow == "Col")
				{
					if (colorrow == "row" || colorrow == "row")
					{
						cout << "\nchoose a row between 1 and 9 ";
						while (!(cin >> row) || row < 1 || row > 9)
						{
							cout << "Invalid! Must be 1-9!: ";
							cin.clear();
							cin.ignore(123, '\n');
						}
						row --;
						firetorpedo(round, row, false);
					}
					else if (colorrow == "col" || colorrow == "Col")
					{
						cout << "\nchoose a Column between A and I ";
						cin >> c_col;
						while (!validColumn(c_col))
						{
							cin >> c_col;
						}
						col = charToInt(c_col);
						firetorpedo(round, col, true);
					}
					else {
						cout << "Invalid! Enter row or col: ";
						cin >> colorrow;
					}
				}
			}
			else if(playershot == "shot" || playershot == "Shot")
			{
				chooseFire2:
				cout << "\nChoose the coordinate that you want to fire (row(1 - 9) col(A - I)): ";
				while (!(cin >> row) || row < 1 || row > 9)
				{
					cout << "Invalid! Must be 1-9!: ";
					cin.clear();
					cin.ignore(123, '\n');
				}
				cin >> c_col;
				while (!validColumn(c_col))
				{
					cin >> c_col;
				}
				col = charToInt(c_col);
				row --;

				if (player1.CheckHit(row, col))
				{
					display.hit();
					shipofplayer1.setHit();
					player2.UpdateEnemyBoard(row, col, true);
					if (shipofplayer1.isSunk()){
						cout << "Player 2 wins!\n";
						break;
					}
				}

				else if(player1.my_ships.getValue(row, col) == 'X')
				{
					//cout <<player2.my_ships.getValue(row, col);
					cout << "\n\nYou've already hit that spot!\n";
					goto chooseFire2;
				}
				else if(player2.enemy_ships.getValue(row, col) == 'O')
				{
					cout <<"\n\nYou've already fire this point!\n";
					goto chooseFire2;
				}
				else
				{
					display.miss();
					player2.UpdateEnemyBoard(row, col, false);
					player1.my_ships.updateBoard(row, col, 'O');
				}
			}
		}
		round++;
		WaitEnter();
	}
}





void Executive::run_PvAi() {

	cout << "\nNow play battleship!\n";

	int round = 1;

	while (!shipofplayer1.isSunk() || !shipofai.isSunk())
	{
		if (round % 2 == 1)
		{
			cout << "Player 1's turn!\n";
			cout << "You have been hit " << shipofplayer1.getHit() << " times\n";
			//Print boards before fire
			display.matchFrame(1, player1.enemy_ships.m_board, player1.my_ships.m_board);

			chooseFire1:
			cout << "\nChoose the coordinate that you want to fire (row(1 - 9) col(A - I)): ";
			while (!(cin >> row) || row < 1 || row > 9)
			{
				// cout <<"row = "<<row<<'\n';
				cout << "Invalid! Must be 1-9!: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
			cin >> c_col;
			while (!validColumn(c_col))
			{
				cin >> c_col;
			}
			col = charToInt(c_col);
			row --;


			if (computer.CheckHit(row, col))
			{
				display.hit();
				shipofai.setHit();
				player1.UpdateEnemyBoard(row, col, true);
				if (shipofai.isSunk()){
					cout << "Player 1 wins!\n";
					break;
				}
			}

			else if(computer.my_ships.getValue(row, col) == 'X')
			{
				//cout <<player2.my_ships.getValue(row, col);
				cout << "\n\nYou've already hit that spot!\n";
				goto chooseFire1;
			}
			else if(player1.enemy_ships.getValue(row, col) == 'O')
			{
				cout <<"\n\nYou've already fire this point!\n";
				goto chooseFire1;
			}
			else
			{
				display.miss();
				player1.UpdateEnemyBoard(row, col, false);
				computer.my_ships.updateBoard(row, col, 'O');
			}
		}
		else
		{
			cout << "BattleshipAI's turn!\n";
			//cout << "You have been hit " << shipofplayer2.getHit() << " times\n";
			//Print boards before fire
			//display.matchFrame(2, player2.enemy_ships.m_board, player2.my_ships.m_board);

			chooseFireAI:
			//cout << "\nChoose the coordinate that you want to fire (row(1 - 9) col(A - I)): ";
			//while (!(cin >> row) || row < 1 || row > 9)
			//{
			//	cout << "Invalid! Must be 1-9!: ";
			//	cin.clear();
			//	cin.ignore(123, '\n');
			//}
			std::string AIshot = "";
			AIshot = computer.fireShot();

			row = AIshot[0];
			c_col = AIshot[1];


			while (!validColumn(c_col))
			{
				cin >> c_col;
			}
			col = charToInt(c_col);
			row --;

			if (player1.CheckHit(row, col))
			{
				display.hit();
				shipofplayer1.setHit();
				computer.UpdateEnemyBoard(row, col, true);
				if (shipofplayer1.isSunk()){
					cout << "BattleshipAI Wins!\n";
					break;
				}
			}

			else if(player1.my_ships.getValue(row, col) == 'X')
			{
				goto chooseFireAI;
			}
			else if(computer.enemy_ships.getValue(row, col) == 'O')
			{
				goto chooseFireAI;
			}
			else
			{
				display.miss();
				computer.UpdateEnemyBoard(row, col, false);
				player1.my_ships.updateBoard(row, col, 'O');
			}
		}
		round++;
		WaitEnter();
	}
}

void Executive::firetorpedo(int turns, int firepostion, bool iscol)
{
	if (turns % 2 == 1)// see if it's player1 or player2
	{
		if (iscol == true)// see if it's a row or col to fire from
		{
			for (int i = 0; i < 9; i++)
			{
				if (player2.CheckHit(i, firepostion))
				{
					display.hit();
					shipofplayer2.setHit();
					player1.UpdateEnemyBoard(i, firepostion, true);
					if (shipofplayer2.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
					break;
				}
				else
				{
					player1.UpdateEnemyBoard(i, firepostion, false);
					if (player2.my_ships.getValue() != 'O')
					{
						player2.my_ships.updateBoard(firepostion, i, 'O');
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (player2.CheckHit(i, firepostion))
				{
					display.hit();
					shipofplayer2.setHit();
					player1.UpdateEnemyBoard(firepostion, i, true);
					if (shipofplayer2.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
					break;
				}
				else
				{
					player1.UpdateEnemyBoard(firepostion, i, false);
					if (player2.my_ships.getValue() != 'O')
					{
						player2.my_ships.updateBoard(firepostion, i, 'O');
					}
				}
			}
		}
	}
	else
	{
		if (iscol == true) // see if it's a row or col to fire from
		{
			for (int i = 0; i < 9; i++)
			{
				if (player1.CheckHit(i, firepostion))
				{
					display.hit();
					shipofplayer1.setHit();
					player2.UpdateEnemyBoard(i, firepostion, true);
					if (shipofplayer1.isSunk()){
						cout << "Player 2 wins!\n";
						break;
					}
					break;
				}
				else
				{
					player2.UpdateEnemyBoard(i, firepostion, false);
					if (player1.my_ships.getValue() != 'O')
					{
						player1.my_ships.updateBoard(firepostion, i, 'O');
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (player1.CheckHit(firepostion, i))
				{
					display.hit();
					shipofplayer1.setHit();
					player2.UpdateEnemyBoard(firepostion, i, true);
					if (shipofplayer1.isSunk()){
						cout << "Player 2 wins!\n";
						break;
					}
					break;
				}
				else
				{
					player2.UpdateEnemyBoard(firepostion, i, false);
					if (player1.my_ships.getValue() != 'O')
					{
						player1.my_ships.updateBoard(firepostion, i, 'O');
					}
				}
			}
		}
	}
}
