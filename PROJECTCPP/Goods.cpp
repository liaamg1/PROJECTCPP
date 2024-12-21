#include "Goods.h"

Goods::Goods(float weight, const std::string& name) : weight(weight), name(name)
{
}

//----->DECONSTRUCTOR<-----

Goods::~Goods()
{
	std::cout << "Destroying Goods" << std::endl;
}

//----->GET<-----

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

//----->SET<-----

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

//----->TO_STRING<-----

std::string Goods::toString() const
{
	return "Weight: " + std::to_string(this->weight) + "\nType: " + this->type + "\nName: " + this->name;
}
