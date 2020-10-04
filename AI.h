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
		 * Default constructor for AI.
		 * @post Initializes the AI for easy difficulty by default.
		 */
		AI();

		/**
		 * Constructor for AI.
		 * @param difficulty - an int, 1 for easy, 2 for med, 3 for hard.
		 * @post the AI has been initialized.
		 */
		AI(int difficulty);

		/**
		 * Destructor for AI.
		 * @post all heap variables that have been initialized have been deleted.
		 */
		~AI();
		
		/**
		 * Fires a shot.
		 * @pre the game should not be over and there should still be open spaces to fire at.
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string fireShot();

		/**
		 * Sets the AI's difficulty
		 * @post The AI's difficulty is changed.
		 */
		void setDifficulty(int difficulty);				

    /*
		 * Returns AI difficutly.
		 * @post returns an int: 1, 2, or 3
		 */
		int getDifficulty() const;

		/**
		 * Function is part of handling the case that the medium difficulty AI hits with a torpedo
		 * @post the AI will start hit tracking on the torpedo hit.
		 */
		void torpedoHit(int row, int col);


	private:

		int m_difficulty;
		// The following vars are used in the medium difficulty AI.
		int* m_prevShot;
		int* m_origHit;
		bool m_trackingHit;
		//bool m_prevShotHit;
		int m_direction; // Direction from hit to search for more hits: 0 up, 1 left, 2 right, 3 down.

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
		 * Used in the process of finding another hit.
		 * @pre the AI must be set to difficulty 2
		 * @post m_direction has been incremented and m_prevShot has been reset to m_origHit
		 */
		void incrementDirection();

		/**
		 * Fires a shot. Hard difficulty.
		 * @post returns a string of length 2 that contains the coordinates to fire at.
		 */
		string shoot3();
};

#endif // AI_H
