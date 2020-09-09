#ifndef SHIP_H
#define SHIP_H
#include  <string>

class Ship{
private:
  int shipnumer;
  int hit;
public:
  Ship();
  ~Ship();
  void setShipNumber();
  int getShipNumber();
  bool checkPosition();
  void setHit();
  int getHit();
  bool isSunk();
};
#endif
