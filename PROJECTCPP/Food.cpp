#include "Food.h"
#include <iostream>

Food::Food() : quantity(0) // Initialisera quantity till 0
{
    setWeight(0.0f);  // Sätter vikt till 0.0
    setName("");      // Sätter namn till en tom sträng
    setType("");      // Sätter typ till en tom sträng
}

Food::~Food()
{
}

void Food::displayInfo() const
{
    // Använd getter-metoder från Goods för att skriva ut information
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