#include "Ship.h"

using namespace std;

Ship::Ship(){

}
Ship::~Ship(){

}
void Ship::setShip(int row, int col, int shipnumber, string direction, char* board[]){
  if (row < 1 || row > 9){
    cout << "invalid row\n";
  }
  else if (col < 1 || col > 9){
    cout << "invalid col\n";
  }
  else{
    if (direction == "up" && col+shipnumber <= 10){
      for (int i=0; i<shipnumber; i++){
        board[shiprow-1][shipcol-1+i] = 'B';
      }
    }
    else if (direction == "right" && row+shipnumber <= 10){
      for (int i=0; i<shipnumber; i++){
        board[shiprow-1+i][shipcol-1] = 'B';
      }
    }
    else if (direction == "down" && col-shipnumber >= 0){
      for (int i=0; i<shipnumber; i++){
        board[shiprow-1][shipcol-1-i] = 'B';
      }
    }
    else if (direction == "left" && row-shipnumber >= 0){
        for (int i=0; i<shipnumber; i++){
          board[shiprow-1-i][shipcol-1] = 'B';
        }
    }
    else{
      cout << "wrong direction\n";
    }
    shipnumber--;
  }
}
}
