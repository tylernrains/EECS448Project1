/**
 * @date 9/25
 * @brief Definitions for class AI
 */

#include "AI.h"
#include <iostream>

using namespace std;


AI::AI(){
	m_difficulty = 1;
	m_direction = 0;
	m_prevShot = nullptr;
	m_origHit = nullptr;
	m_trackingHit = false;
}

AI::AI(int difficulty) {
	m_difficulty = difficulty;
	
	m_trackingHit = false;
	m_direction = 0;
	if (m_difficulty == 2) {
		m_prevShot = new int[2];
		m_prevShot[0] = m_prevShot[1] = 10;
		m_origHit = new int[2];
	} else {
		m_prevShot = nullptr;
		m_origHit = nullptr;
	}

	if (m_difficulty == 3) {

		m_prevShot = new int[2];
		m_prevShot[0] = 1;
		m_prevShot[1] = 65;		

	}

}

AI::~AI() {
	if (m_prevShot != nullptr)
		delete[] m_prevShot;
	if (m_origHit != nullptr)
		delete[] m_origHit;
}

void AI::setDifficulty(int difficulty)
{
	// Deleting these variables on the off-chance they've been initialized before difficulty change.
	// This prevents any possible memory leakage.
	if (m_prevShot != nullptr)
		delete[] m_prevShot;
	if (m_origHit != nullptr)
		delete[] m_origHit;


	m_difficulty = difficulty;
	if (m_difficulty == 2)
	{
		m_prevShot = new int[2];
		m_prevShot[0] = m_prevShot[1] = 10;
		m_origHit = new int[2];
	}
	else if (m_difficulty == 3) {
		m_prevShot = new int[2];
		m_prevShot[0] = 1;
		m_prevShot[1] = 65;
		m_origHit = nullptr;
	} else	{
		m_prevShot = nullptr;
		m_origHit = nullptr;
	}	
}

string AI::fireShot() {
	switch (m_difficulty) {
		case 1 : return shoot1(); break;
		case 2 : return shoot2(); break;
		case 3 : return shoot3(); break;
		default : return ""; // If the default is ever used, then m_difficulty was initialized wrong.
	}
}

string AI::shoot1() {

	string coord = "";
       	coord += (char)(rand() % 9 + '1');
	coord += (char)(rand() % 9 + 'A');
	
	return coord;
}

string AI::shoot2() {
	string coord = "";

	//m_prevShotHit = isPrevShotHit();

	if (!m_trackingHit) {
		if (!m_prevShotHit) {
			// Storing the shot coords
			m_prevShot[0] = rand() % 9;
			m_prevShot[1] = rand() % 9;
		} else {
			m_trackingHit = true;
			// Storing the coords of the original hit
			m_origHit[0] = m_prevShot[0];
			m_origHit[1] = m_prevShot[1];
		}
	}

	if (m_trackingHit) {
		if (m_direction == 0) { // Trying up
			if (m_prevShotHit) {
				// Storing coords of next shot
				m_prevShot[0] = m_prevShot[0]-1;

				if (m_prevShot[0] < 0) // Next shot would be out of bounds
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 1) { // Trying left
			if (m_prevShotHit) {
				m_prevShot[1] = m_prevShot[1]-1;

				if (m_prevShot[1] < 0)
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 2) { // Trying down
			if (m_prevShotHit) {
				m_prevShot[0] = m_prevShot[0]+1;

				if (m_prevShot[0] >= 9)
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 3) { // Trying right
			if (m_prevShotHit) {
				m_prevShot[1] = m_prevShot[1]+1;

				if (m_prevShot[1] >= 9)
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction > 3) { // Has tried all directions
			m_prevShot[0] = rand() % 9;
			m_prevShot[1] = rand() % 9;
			m_trackingHit = false;
			m_direction = 0;
		}

	}
	
	coord += (char)(m_prevShot[0] + '1');
	coord += (char)(m_prevShot[1] + 'A');
	cout << "Firing shot at " + coord + ". Hit tracking=" << m_trackingHit << endl;
	return coord;
}

void AI::incrementDirection() {
	m_direction++;
	m_prevShot[0] = m_origHit[0];
	m_prevShot[1] = m_origHit[1];
	m_prevShotHit = true;
}

void AI::torpedoHit(int row, int col) {
	m_trackingHit = true;
	m_origHit[0] = m_prevShot[0] = row;
	m_origHit[1] = m_prevShot[1] = col;
}

bool AI::isPrevShotHit() {

	if (m_prevShot[0] < 9 && m_prevShot[0] >= 0 && m_prevShot[1] < 9 && m_prevShot[1] >= 0) {
		if (enemy_ships.getValue(m_prevShot[0], m_prevShot[1]) == 'X') {
			enemy_ships.updateBoard(m_prevShot[0], m_prevShot[1], 'O');
			return true;
		} else
			return false;
	} else
		return false;
}

	int counter_diag = 0;

string AI::shoot3() { //Hard Difficulty
	
	string coord = "1A";


	if(m_trackingHit == false){ // m_trackingHit is only used in the hardai for the sake
								// of seeing if it is the first shot it makes. It does
								// nothing else after. It does not track hits at all.
		m_trackingHit = true;
		m_prevShot[0] = 1;
		m_prevShot[1] = 65; //A

		coord[0] = m_prevShot[0];		//actual int - col
		coord[1] = char(m_prevShot[1]);	//ACII value - row
		return coord;
	}


	if (m_prevShot[0] == 9){	//if end of row, start next row

		m_prevShot[0] = 0;
		m_prevShot[1] += 1;	

	} else {					//else add one to col number

		m_prevShot[0]++;

	}

	coord[0] = m_prevShot[0];		//actual int - col
	coord[1] = char(m_prevShot[1]);	//ACII value - row

	return coord;
}


int AI::getDifficulty() const {

	return m_difficulty;

}
