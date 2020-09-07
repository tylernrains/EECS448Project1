#ifndef SHIP_H
#define SHIP_H

class Ship{
private:

public:
  ship();
  ~ship();
  void setShip(int row, int col, int shipnumber, string direction, char* board[]);
};
#endif
