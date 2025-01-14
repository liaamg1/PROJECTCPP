#include "Food.h"

Food::Food(int quantity, float weight, const std::string& name) : quantity(quantity), Goods(weight, name)
{
    std::cout << "Constructing Food" << std::endl;
}

//----->DECONSTRUCTOR<-----

Food::~Food()
{
    std::cout << "Destroying Food" << std::endl;
}

//----->SET<-----

void Food::setQuantity(int quantity)
{
    this->quantity = quantity;
}

//----->GET<-----

int Food::getQuantity() const
{
    return this->quantity;
}

std::string Food::toString() const
{
    return  "\nFood\nQuantity: " + std::to_string(this->quantity) + "\n" + "Weight: " + std::to_string(getWeight()) + "\nName: " + getName();
}
