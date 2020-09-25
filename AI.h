/**
 * @date 9/25
 * @brief Header file for the AI class, subclass of Player.
 */

#ifndef AI_H
#define AI_H

#include "player.h"
#include <string>

using namespace std;

class AI : public Player
{
	public:
		/**
		 * Constructor for AI.
		 * @param difficulty - an int, 0 for easy, 1 for med, 2 for hard.
		 */
		AI(int difficulty);

		~AI();

		/**
		 * TODO delete this eventually
		 * All of the methods inherited from Player should function fine for the AI class.
		 * I don't immediately see any need for overriding them.
		 * -Trey
		 */
		
		/**
		 * Fires a shot.
		 * @pre the game should not be over and there should still be open spaces to fire at on the opponent's board
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string fireShot();

	private:

		int m_difficulty;

		/**
		 * Fires a shot. Easy difficulty.
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string shoot1();

		/**
		 * Fires a shot. Medium difficulty.
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string shoot2();

		/**
		 * Fires a shot. Hard difficulty.
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string shoot3();

};

#endif
