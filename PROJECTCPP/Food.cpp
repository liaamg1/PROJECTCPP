#include "Food.h"

Food::Food(int quantity, float weight, const std::string& type, const std::string& name) : quantity(quantity), Goods(weight, type, name)
{
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
    return std::to_string(this->quantity) + "\n" + Goods::toString();
}
