#include "Player.h"

Player::Player(): stepCounter(0), waitNumber(0)
{
	position.x = 0;
	position.y = 0;
}

Player::Player(Point _position): stepCounter(0), waitNumber(0)
{
	position.x = position.x;
	position.y = position.y;
}

void Player::Move(int x, int y)
{
	position.x = x;
	position.y = y;
}
