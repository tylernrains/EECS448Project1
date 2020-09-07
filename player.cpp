//Player.cpp

#include "player.h"

Player::Player() {}

Player::~Player() {}

void Player::printMyShips()
{
    my_ships.printBoard();
}

void Player::printEnemyShips()
{
    enemy_ships.printBoard();
}