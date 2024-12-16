#include "Goods.h"

Goods::Goods() :weight(0), type("?"), name("?")
{
}

Goods::~Goods()
{
}

std::string Goods::getName() const
{
	return this->name;
}

float Goods::getWeight() const
{
	return this->weight;

}

std::string Goods::getType() const
{
	return this->type;

}

void Goods::setWeight(float weight)
{
	this->weight = weight;
}



void Goods::setName(std::string name)
{
	this->name = name;

}

void Goods::setType(std::string type)
{
	this->type = type;
}
