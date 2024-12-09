#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>

class Player
{
public:
	Player(int capital, const std::string& name);
	~Player();

	//GET
	int getBalance();

private:
	int balance;
	std::string name;
};
#endif // !PLAYER_H
