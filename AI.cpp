/**
 * @date 9/25
 * @brief Definitions for class AI
 */

#include "AI.h"

using namespace std;

AI::AI(int difficulty) {
	m_difficulty = difficulty;
}

AI::~AI() {}

string AI::fireShot() {
	switch (m_difficulty) {
		case 0 : return shoot1(); break;
		case 1 : return shoot2(); break;
		case 2 : return shoot3(); break;
		default : return ""; // If the default is ever used, then m_difficulty was initialized wrong.
	}
}

string AI::shoot1() {
	// TODO fill in method definition
	return "";
}

string AI::shoot2() {
	// TODO fill in method definition
	return "";
}

string AI::shoot3() {
	// TODO fill in method definition
	return "";
}
