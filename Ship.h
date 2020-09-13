#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>

class Ship{
private:
  int shipnumber;
  int hit;
public:
  /**
  	* @pre: None
  	* @post: Initializes all numeric data to zero
  	**/
  Ship();
  /**
  	* @pre: None
  	* @post: None
  	**/
  ~Ship();
  /**
  	* @post: assigns shipnum to shipnumber
  	* @param: shipnum, to be assigned to shipnumber
  	**/
  void setShipNumber(int shipnum);
  /**
  	* @pre: None
  	* @return: shipnumber, the number of ship of each player
  	**/
  int getShipNumber();
  /**
  	* @post: count the number of hit after hitting
  	* @param: None
  	**/
  void setHit();
  /**
  	* @pre: None
  	* @return: hit, the number of hit of each player
  	**/
  int getHit();
  /**
  	* @post all ship is sunk
  	* @return: intrue if the number of ship equal to the number of hit, false otherwise
  	**/
  bool isSunk();
};
#endif
