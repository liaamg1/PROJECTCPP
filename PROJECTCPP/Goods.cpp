#include "Goods.h"

Goods::Goods(float weight, const std::string& type, const std::string& name) : weight(weight), type(type), name(name)
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

//----->EXPAND_CONTAINERS<-----

bool Goods::operator==(const Goods& other) const
{
	return false;
}