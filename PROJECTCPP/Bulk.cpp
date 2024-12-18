#include "Bulk.h"

Bulk::Bulk(float volume, float weight, const std::string& type, const std::string& name) : volume(volume), Goods(weight, type, name)
{
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
    return std::to_string(this->volume) + "\n" + Goods::toString();
}
//BER�KNA VOLUME OM BARA WEIGHT �R GIVET