#include "Goods.h"

Goods::Goods(float weight, const std::string& name) : weight(weight), name(name)
{
	std::cout << "Constructing Goods" << std::endl;
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

//----->SET<-----

void Goods::setWeight(float weight)
{
	this->weight = weight;
}


void Goods::setName(std::string name)
{
	this->name = name;
}

