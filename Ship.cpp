#include "Ship.h"
using namespace std;

Ship::Ship(){
  shipnumber = 0;
  hit = 0;
}
Ship::~Ship(){

}
void Ship::setShipNumber(int shipnum){
  shipnumber = shipnum;
}
int Ship::getShipNumber(){
  return shipnumber;
}
void Ship::setHit(){
  hit++;
}
int Ship::getHit(){
  return hit;
}
bool Ship::isSunk(){
  if (hit == shipnumber){
    return true;
  }
  else{
    return false;
  }
}
