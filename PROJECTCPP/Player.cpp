#include "Player.h"

Player::Player(int balance, const std::string& name) :balance(balance), name(name)
{
}

Player::~Player()
{
}

int Player::getBalance()
{
	return this->balance;
}


