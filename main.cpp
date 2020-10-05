#include <iostream>
#include <string>
#include "Executive.h"
#include <time.h>

int main(){

	srand(time(NULL)); //initalizes a random seed at the start of the program

	std::string horizontal_bar = "-----------------------------------------------------------------------\n";
	std::string battleship_text = " 		            BATTLESHIP          			  \n";

	for (int i = 0; i < 3; i++) std::cout << endl;
	std::cout << horizontal_bar;
	for (int i = 1; i <= 1; i++) std::cout << endl;
	std::cout << battleship_text;
	for (int i = 1; i <= 1; i++) std::cout << endl;
	std::cout << horizontal_bar;
	for (int i = 0; i < 3; i++) std::cout << endl;

	Executive exec;
	int Gameplay_opt;

	while (true){

		std::cout << "Welcome! How would you like to play Battleship?\n\n  1) Player vs Player\n  2) Player vs AI\n\nEnter choice: ";
		std::cin >> Gameplay_opt;

	if(cin.fail()){

			cin.clear();
			cin.ignore();
			Gameplay_opt = 0;
	}

	if (Gameplay_opt == 1){

		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
		exec.run_setup_PvP();
		break;

	} else if (Gameplay_opt == 2) {

		std::cout << "\n";
		exec.run_setup_PvAi();
		break;

	 } else {

		 std::cout << "\n\nInvalid! Enter option '1' or '2'\n\n";
		 
	 }
	}
	
	std::cout << "\nClosing Battleship\n\n";

	return(0);
}
