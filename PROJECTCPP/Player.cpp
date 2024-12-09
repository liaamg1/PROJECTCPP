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

void Player::addMoney(int amount)
{	
	std::cout << "Enter an amount to add to your balance: ";
	std::cin >> amount;
	this->balance += amount;
	std::cout << "Current balance: " << balance <<"$"<< std::endl;
}

void Player::subtractMoney(int amount)
{
	std::cout << "Enter an amount to withdra from your balance: ";
	std::cin >> amount;
	this->balance -= amount;
	std::cout << "Current balance: " << balance << "$" << std::endl;
}


