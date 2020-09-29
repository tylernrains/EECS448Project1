/**
 * @date 9/25
 * @brief Definitions for class AI
 */

#include "AI.h"
#include <time.h>
#include <iostream>

using namespace std;

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
}

AI::~AI() {
	if (m_prevShot != nullptr)
		delete[] m_prevShot;
	if (m_origHit != nullptr)
		delete[] m_origHit;
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
	//srand(time(NULL));

	string coord = "";
       	coord += (char)(rand() % 9 + '1');
	coord += (char)(rand() % 9 + 'A');
	
	return coord;
}

string AI::shoot2() {
	string coord = "";

	if (!isPrevShotHit() && !m_trackingHit) {
		// Storing the shot coords
		m_prevShot[0] = rand() % 9;
		m_prevShot[1] = rand() % 9;
	} else if (isPrevShotHit()) {
		m_trackingHit = true;
		// Storing the coords of the original hit
		m_origHit[0] = m_prevShot[0];
		m_origHit[1] = m_prevShot[1];
	}

	if (m_trackingHit) {
		if (m_direction == 0) { // Trying up
			if (isPrevShotHit()) {
				// Storing coords of next shot
				m_prevShot[0] = m_prevShot[0]-1;

				if (m_prevShot[0] < 0) // Next shot would be out of bounds
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 1) { // Trying left
			if (isPrevShotHit()) {
				m_prevShot[1] = m_prevShot[1]-1;

				if (m_prevShot[1] < 0)
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 2) { // Trying down
			if (isPrevShotHit()) {
				m_prevShot[0] = m_prevShot[0]+1;

				if (m_prevShot[0] >= 9)
					incrementDirection();
			} else
				incrementDirection();
		}

		if (m_direction == 3) { // Trying right
			if (isPrevShotHit()) {
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

	return coord;
}

void AI::incrementDirection() {
	m_direction++;
	m_prevShot[0] = m_origHit[0];
	m_prevShot[1] = m_origHit[1];
}

bool AI::isPrevShotHit() {
	// TODO change so it's not looking for an X, b/c this leads it to re-do hit tracking on previous hits.
	if (m_prevShot[0] < 9 && m_prevShot[0] >= 0 && m_prevShot[1] < 9 && m_prevShot[1] >= 0)
		return (enemy_ships.getValue(m_prevShot[0], m_prevShot[1]) == 'X');
	else
		return false;
}

string AI::shoot3() {
	// TODO fill in method definition
	return "";
}
