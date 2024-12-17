#include "Food.h"

Food::Food(int quantity = 0, float weight, const std::string& type, const std::string& name) : quantity(quantity), Goods(weight), Goods(type), Goods(name)
{
}

Food::~Food()
{
}

void Food::displayInfo() const
{
    // Anv�nd getter-metoder fr�n Goods f�r att skriva ut information
    std::cout << "Food Quantity: " << getQuantity() << " units" << std::endl;
    std::cout << "Food Weight: " << getWeight() << " kg" << std::endl;
    std::cout << "Food Type: " << getType() << std::endl;
    std::cout << "Food Name: " << getName() << std::endl;
}

void Food::setQuantity(int quantity)
{
    this->quantity = quantity;
}

int Food::getQuantity() const
{
    return this->quantity;
}