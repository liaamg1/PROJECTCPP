#include "Bulk.h"

Bulk::Bulk(float volume, float weight, const std::string& name) : volume(volume), Goods(weight, name)
{
    std::cout << "Constructing Bulk" << std::endl;
}

//----->DECONSTRUCTOR<-----

Bulk::~Bulk()
{
    std::cout << "Destroying Bulk" << std::endl;
}

//----->SET<-----

void Bulk::setVolume(float volume) 
{
    this->volume = volume;
}

//----->GET<-----

float Bulk::getVolume() const
{
    return this->volume;
}
std::string Bulk::toString() const
{
    return "\nBulk\nVolume: " + std::to_string(this->volume) + "\n" + Goods::toString();
}
//BERÄKNA VOLUME OM BARA WEIGHT ÄR GIVET