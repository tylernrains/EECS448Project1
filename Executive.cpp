
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
	// This will be the number of ships used for both players.

	do {
		cin >> shipnum;
		if (shipnum < 1 || shipnum > 5) {
			cout << "Invalid! Must be 1-5!: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
	} while (shipnum < 1 || shipnum > 5);

	player1.SetNumShips(shipnum);
	shipofplayer1.setShipNumber(numShipCoords(shipnum));

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
				cout << "Orient the ship Up, Down, Left, or Right from pivot? (U, D, L, R): ";
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

	cout <<"Switch to Player 2 Setup!\n";
	WaitEnter();


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
				cout << "Orient the ship Up, Down, Left, or Right from pivot? (U, D, L, R): ";
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

void Executive::run_setup_PvAi()
{
	char arr_directions[4] = {'U', 'D', 'L', 'R'};

	cout << "How many ships do you want to place in the grid (choose from 1 to 5)? ";
	// This will be the number of ships for both player 1 and computer
	do {
		cin >> shipnum;
		if (shipnum < 1 || shipnum > 5) {
			cout << "Invalid! Must be 1-5!: ";
			cin.clear();
			cin.ignore(123, '\n');
		}

	} while (shipnum < 1 || shipnum > 5);

	//sets the AI's difficulty
	int difficulty = 0;
	std::cout << "What difficulty would you like the AI to be? (1 = easy, 2 = medium, 3 = hard): ";
	std::cin >> difficulty;
	while (difficulty < 1 || difficulty > 3)
	{
		std::cout << "That is not a valid difficulty, try again (1 = easy, 2 = medium, 3 = hard): ";
		std::cin.clear();
		std::cin.ignore(123, '\n');		
		std::cin >> difficulty;
	}
	computer.setDifficulty(difficulty);

	//Place player 1's ships
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
				cout << "Orient the ship Up, Down, Left, or Right from pivot? (U, D, L, R): ";
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

	player1.SetNumShips(shipnum);
	shipofplayer1.setShipNumber(numShipCoords(shipnum));

	computer.SetNumShips(shipnum);
	shipofai.setShipNumber(numShipCoords(shipnum));

	//place the AI's ships
	for (int i = 1; i <= shipnum; ++i)
	{
		while (!computer.PlaceShip(i, std::rand() % 9, std::rand() % 9, arr_directions[std::rand() % 4])) {}		}

	std::cout << "\nThe AI's ships have been placed.\n\n";
	WaitEnter();
	run_PvAi();
}


void Executive::run_PvP()
{
	cout << "\nNow play battleship!\n";

	int round = 1;
	bool player1torpedo = true;
	bool player2torpedo = true;
	string torpedodirection = "";
	string playershot = "";

	// Explaining the torpedo
	cout << "\n--NOTICE FOR BOTH PLAYERS--\nYour ships are equipped with torpedos!\n";
	cout << "When fired, a torpedo will travel along a straight line until it hits a target\n";
	cout << "or until it travels out of range, at which point it will stop.\n";
	cout << "\nUse these with care, as you have a very limited supply of them!\n\n";

	while (!shipofplayer1.isSunk() || !shipofplayer2.isSunk())
	{
		if (round % 2 == 1)
		{
			cout << "Player 1's turn!\n";
			cout << "You have been hit " << shipofplayer1.getHit() << " times.\n";
			//Print boards before fire
			display.matchFrame(1, player1.enemy_ships.m_board, player1.my_ships.m_board);

			if (player1torpedo == true) {
				do
				{
					cout << "\nDo you want to fire a torpedo or a regular shot?";
					cout << "\nEnter 'torp' for the torpedo and 'shot' for the regular shot: ";
					cin >> playershot;
				} while(playershot != "torp" && playershot != "shot");
			} else // Player1 doesn't have torpedo available.
				playershot = "shot";

			if (playershot == "torp")
			{
				string colorrow = "";

				do
				{
					cout << "\nEnter 'col' to shoot from a column and 'row' to shoot from a row: ";
					cin >> colorrow;
				} while (colorrow != "row" && colorrow != "col");

				if (colorrow == "row") // fires a torp from a row
				{
					cout << "\nchoose a row between 1 and 9: ";
					while (!(cin >> row) || row < 1 || row > 9)
					{
						cout << "Invalid! Must be 1-9!: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					row--;

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'f' for forwards and 'b' for backwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "f" && torpedodirection != "b");

					firetorpedo(torpedodirection, row, false, player1, player2, shipofplayer2);
					if (shipofplayer2.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
				}
				else if (colorrow == "col") // fires a torp from a column
				{
					cout << "\nchoose a Column between A and I: ";
					cin >> c_col;
					while (!validColumn(c_col))
					{
						cin >> c_col;
					}
					col = charToInt(c_col);

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'u' for upwards and 'd' for downwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "u" && torpedodirection != "d");

					firetorpedo(torpedodirection, col, true, player1, player2, shipofplayer2);
					if (shipofplayer2.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
				}
				player1torpedo = false;
			}
			else if(playershot == "shot") // Firing a normal shot.
			{
				chooseFire1:
				cout << "\nChoose the coordinate that you want to fire at (row(1 - 9) col(A - I)): ";
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
				row--;


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
					cout << "\n\nYou've already hit that spot!\n";
					goto chooseFire1;
				}
				else if(player1.enemy_ships.getValue(row, col) == 'O')
				{
					cout <<"\n\nYou've already fired at that spot!\n";
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
			cout << "You have been hit " << shipofplayer2.getHit() << " times.\n";
			//Print boards before fire
			display.matchFrame(2, player2.enemy_ships.m_board, player2.my_ships.m_board);

			if (player2torpedo == true) {
				do
				{
					cout << "\nDo you want to fire a torpedo or a regular shot?";
					cout << "\nEnter 'torp' for the torpedo and 'shot' for the regular shot: ";
					cin >> playershot;
				} while(playershot != "torp" && playershot != "shot");
			} else // Player2 doesn't have a torpedo available
				playershot = "shot";

			if (playershot == "torp") // Firing a torpedo
			{
				string colorrow = "";

				do
				{
					cout << "\nEnter 'col' to shoot from a column and 'row' to shoot from a row: ";
					cin >> colorrow;
				} while (colorrow != "row" && colorrow != "col");

				if (colorrow == "row") // fires a torp from a row
				{
					cout << "\nchoose a row between 1 and 9: ";
					while (!(cin >> row) || row < 1 || row > 9)
					{
						cout << "Invalid! Must be 1-9!: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					row--;

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'f' for forwards and 'b' for backwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "f" && torpedodirection != "b");

					firetorpedo(torpedodirection, row, false, player2, player1, shipofplayer1);
					if (shipofplayer1.isSunk()){
						cout << "Player 2 wins!\n";
						break;
					}
				}
				else if (colorrow == "col") // fires a torp from a column
				{
					cout << "\nchoose a Column between A and I: ";
					cin >> c_col;
					while (!validColumn(c_col))
					{
						cin >> c_col;
					}
					col = charToInt(c_col);

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'u' for upwards and 'd' for downwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "u" && torpedodirection != "d");

					firetorpedo(torpedodirection, col, true, player2, player1, shipofplayer1);
					if (shipofplayer1.isSunk()){
						cout << "Player 2 wins!\n";
						break;
					}
				}
				player2torpedo = false;
			}
			else if(playershot == "shot")
			{
				chooseFire2:
				cout << "\nChoose the coordinate that you want to fire at (row(1 - 9) col(A - I)): ";
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
				row--;

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
					cout << "\n\nYou've already hit that spot!\n";
					goto chooseFire2;
				}
				else if(player2.enemy_ships.getValue(row, col) == 'O')
				{
					cout <<"\n\nYou've already fired at that spot!\n";
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

		if (round % 20 == 0)
		{
			cout << "TORPEDO RECHARGED\n";
	 		player1torpedo = true;
			player2torpedo = true;
		}

		round++;
		WaitEnter();
	}
}

void Executive::run_PvAi()
{
	cout << "\nNow play battleship!\n";

	//Explaining the torpedo
	cout << "\n--NOTICE TO THE PLAYER--\n";
	cout << "Both yours and the enemy's ships are equipped with torpedos!\n";
	cout << "When fired, a torpedo will travel along a straight line until it hits a target\n";
	cout << "or until it travels out of range, at which point it will stop.\n";
	cout << "\nUse these with care, as you have a very limited supply of them!\n\n";

	int round = 1;
	bool player1torpedo = true;
	bool computertorpedo = true;

	string torpedodirection = "";
	string playershot = "";

	while (!shipofplayer1.isSunk() || !shipofai.isSunk())
	{

		if (round % 2 == 1)
		{
			cout << "Player 1's turn!\n";
			cout << "You have been hit " << shipofplayer1.getHit() << " times.\n";
			//Print boards before fire
			display.matchFrame(1, player1.enemy_ships.m_board, player1.my_ships.m_board);

			if (player1torpedo == true) {
				do
				{
					cout << "\nDo you want to fire a torpedo or a regular shot?";
					cout << "\nEnter 'torp' for the torpedo and 'shot' for the regular shot: ";

					cin >> playershot;
				} while(playershot != "torp" && playershot != "shot");
			} else // The player doesn't have a torpedo available.
				playershot == "shot";

			if (playershot == "torp" && player1torpedo) // Shooting a torpedo
			{
				string colorrow = "";

				do
				{
					cout << "\nEnter 'col' to shoot from a column and 'row' to shoot from a row: ";
					cin >> colorrow;
				} while (colorrow != "row" && colorrow != "col");

				if (colorrow == "row")
				{
					cout << "\nchoose a row between 1 and 9: ";
					while (!(cin >> row) || row < 1 || row > 9)
					{
						cout << "Invalid! Must be 1-9!: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					row--;

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'f' for forwards and 'b' for backwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "f" && torpedodirection != "b");

					firetorpedo(torpedodirection, row, false, player1, computer, shipofai);
					if (shipofai.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
				}
				else if (colorrow == "col")
				{
					cout << "\nchoose a Column between A and I: ";
					cin >> c_col;
					while (!validColumn(c_col))
					{
						cin >> c_col;
					}
					col = charToInt(c_col);

					do
					{
						cout << "\nEnter what direction you want to fire you torpedo";
						cout << "\n'u' for upwards and 'd' for downwards: ";
						cin >> torpedodirection;
					} while (torpedodirection != "u" && torpedodirection != "d");

					firetorpedo(torpedodirection, col, true, player1, computer, shipofai);
					if (shipofai.isSunk()){
						cout << "Player 1 wins!\n";
						break;
					}
				}
				player1torpedo = false;
			}
			else if(playershot == "shot" || !player1torpedo) // Shooting a normal shot
			{
				chooseFire1:
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
				row--;


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
					cout << computer.my_ships.getValue(row, col);
					cout << "\n\nYou've already hit that spot!\n";
					goto chooseFire1;
				}
				else if(player1.enemy_ships.getValue(row, col) == 'O')
				{
					cout <<"\n\nYou've already fired at that spot!\n";
					goto chooseFire1;
				}
				else
				{
					display.miss();
					player1.UpdateEnemyBoard(row, col, false);
					computer.my_ships.updateBoard(row, col, 'O');
				}
			}
			WaitEnter();
		}
		else
		{
			cout << "BattleshipAI's turn!\n";

			chooseFireAI:

			std::string AIshot = "";

			if(computer.getDifficulty() == 3){ // AI is set to Hard

				while(true){

					AIshot = computer.fireShot();
					row = AIshot[0];
					c_col = AIshot[1];

					col = charToInt(c_col);

					if (player1.Only_CheckHit(row, col) == true){
						break;
					}
				}

			} else {	//AI - not set to Hard

				if (computertorpedo == true) {	// AI torp
				
					int comp_torp_shot = rand() % 9;
					string direction = ((int)(rand() % 2) == 0) ? "f" : "b";

					if (computer.getDifficulty() == 2)
						direction += '2'; // Used for medium AI

					bool iscol = (int)(rand() % 2);

					firetorpedo(direction, comp_torp_shot, iscol, computer, player1, shipofplayer1);
					if (shipofplayer1.isSunk()){
						cout << "BattleshipAI Wins!\n";
						break;
					}
					computertorpedo = false;
					goto skip;
				}


				AIshot = computer.fireShot();

				row = (int)(AIshot[0]-'1');
				c_col = AIshot[1];

				col = charToInt(c_col);
			}

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
				computer.UpdateEnemyBoard(row, col, false);
				goto chooseFireAI;
			}
			else if(computer.enemy_ships.getValue(row, col) == 'O')
			{
				computer.UpdateEnemyBoard(row, col, false);
				goto chooseFireAI;
			}
			else
			{
				display.miss();
				computer.UpdateEnemyBoard(row, col, false);
				player1.my_ships.updateBoard(row, col, 'O');
			}
		}

		skip:
		round++;
	}
}


void Executive::firetorpedo(string direction, int firepostion, bool iscol, Player& friendly, Player& enemy, Ship& enemyShip)
{
	char temp = ' '; // Used for medium difficulty AI
	if (direction.length() == 2)
		temp = direction[1];

	direction = direction[0];
	if(direction == "f" || direction == "d")
	{
		if (iscol == true)// see if it's a row or col to fire from
		{
			for (int i = 0; i < 9; i++)
			{
				if (enemy.CheckHit(i, firepostion))
				{
					display.hit();
					enemyShip.setHit();
					friendly.UpdateEnemyBoard(i, firepostion, true);
					if (temp == '2') // Used in medium difficulty AI
						computer.torpedoHit(i, firepostion);
					return;//exits the method
				}
				else
				{
					if (enemy.my_ships.getValue(i, firepostion) == 'X') //if the torpedo comes across a previously hit ship, it stops
					{
						return;
					}
					friendly.UpdateEnemyBoard(i, firepostion, false);
					enemy.my_ships.updateBoard(i, firepostion, 'O');
				}
			}
			display.miss();
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				if (enemy.CheckHit(firepostion, i))
				{
					display.hit();
					enemyShip.setHit();
					friendly.UpdateEnemyBoard(firepostion, i, true);

					if (temp == '2')
						computer.torpedoHit(firepostion, i);
					return;//exits the method
				}
				else
				{
					if (enemy.my_ships.getValue(firepostion, i) == 'X') //if the torpedo comes across a previously hit ship, it stops
					{
						return;
					}					
					friendly.UpdateEnemyBoard(firepostion, i, false);
					enemy.my_ships.updateBoard(firepostion, i, 'O');
				}
			}
			display.miss();
		}
	}
	else
	{
		if (iscol == true)// see if it's a row or col to fire from
		{
			for (int i = 8; i >= 0; i--)
			{
				if (enemy.CheckHit(i, firepostion))
				{
					display.hit();
					enemyShip.setHit();
					friendly.UpdateEnemyBoard(i, firepostion, true);
					if (temp == '2')
						computer.torpedoHit(i, firepostion);
					return;//exits the method
				}
				else
				{
					if (enemy.my_ships.getValue(i, firepostion) == 'X') //if the torpedo comes across a previously hit ship, it stops
					{
						return;
					}					
					friendly.UpdateEnemyBoard(i, firepostion, false);
					enemy.my_ships.updateBoard(i, firepostion, 'O');
				}
			}
			display.miss();
		}
		else
		{
			for (int i = 8; i >= 0; i--)
			{
				if (enemy.CheckHit(firepostion, i))
				{
					display.hit();
					enemyShip.setHit();
					friendly.UpdateEnemyBoard(firepostion, i, true);
					if (temp == '2')
						computer.torpedoHit(firepostion, i);
					return;//exits the method
				}
				else
				{
					if (enemy.my_ships.getValue(firepostion, i) == 'X') //if the torpedo comes across a previously hit ship, it stops
					{
						return;
					}					
					friendly.UpdateEnemyBoard(firepostion, i, false);
					enemy.my_ships.updateBoard(firepostion, i, 'O');
				}
			}
			display.miss();
		}
	}
}
