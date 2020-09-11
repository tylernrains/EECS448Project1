#include <iostream>
#include <string>
#include "Executive.h"

int main(){

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
	exec.run();

	return(0);
}
