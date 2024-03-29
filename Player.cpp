#include "Player.h"

Player::Player(): stepCounter(0), waitInRowCounter(0), isActivate(true), roundCounter(0), blocked(false)
{
	position.x = 0;
	position.y = 0;
}

Player::Player(Point _position): stepCounter(0), waitInRowCounter(0), isActivate(true), roundCounter(0), blocked(false)
{
	position.x = position.x;
	position.y = position.y;
}

void Player::SetPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}

void Player::SetPosition(Point _position)
{
	position.x = _position.x;
	position.y = _position.y;
}

void Player::MoveTo(int x, int y)
{
	position.x = x;
	position.y = y;
	stepCounter++;
	waitInRowCounter = 0;
}

void Player::MoveTo(Point _position)
{
	position.x = _position.x;
	position.y = _position.y;
	stepCounter++;
	waitInRowCounter = 0;
}

void Player::Wait()
{
	waitInRowCounter++;
	if (waitInRowCounter > 3)
		blocked = true;
}
