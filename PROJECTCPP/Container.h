#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <iostream>
#include <string>

class Container {
private:
    float maxWeight;  // Maxvikt
    float usedWeight; // Använd vikt
    std::string containerType;  // Typ av container (Bulk, Food, etc.)

public:
    Container(float maxWeight, const std::string& containerType);
        
    float getMaxWeight() const;
    float getUsedWeight() const;
    std::string getContainerType() const;
};

#endif
