#include "Goods.h"

Goods::Goods(int weight, int amount, std::string& type, std::string& pallet) : weight(weight), amount(amount), type(type), pallet(pallet)
{
}

Goods::~Goods()
{
}

//----->GET<-----

int Goods::getWeight()
{
	return this->weight;
}

int Goods::getAmount()
{
	return this->amount;
}

std::string Goods::getType() const
{
	return this->type;
}

std::string Goods::getPallet() const
{
	return this->pallet;
}

//----->SET<-----

void Goods::setWeight(int weight)
{
	this->weight = weight;
}

void Goods::setAmount(int amount)
{
	this->amount = amount;
}

void Goods::setType(std::string& type)
{
	this->type = type;
}

void Goods::setPallet(std::string& pallet)
{
	this->pallet = pallet;
}

