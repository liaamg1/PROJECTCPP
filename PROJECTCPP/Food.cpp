#include "Food.h"
#include <iostream>

Food::Food() : quantity(0) // Initialisera quantity till 0
{
    setWeight(0.0f);  // S�tter vikt till 0.0
    setName("");      // S�tter namn till en tom str�ng
    setType("");      // S�tter typ till en tom str�ng
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