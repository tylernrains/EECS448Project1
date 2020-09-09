#ifndef SHIP_H
#define SHIP_H
#include  <string>

class Ship{
private:
  int shipnumber;
  int hit;
public:
  Ship();
  ~Ship();
  void setShipNumber(int number);
  int getShipNumber();
  bool checkPosition(int row, int col, int sizeofship, string direction);
  void setHit();
  int getHit();
  bool isSunk();
};
#endif
