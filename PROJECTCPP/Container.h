#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <iostream>
#include <string>

class Container {
protected:
    float maxWeight;  // Maxvikt
    float usedWeight; // Använd vikt
    std::string containerType;  // Typ av container (Bulk, Food, etc.)

public:
    Container(float maxWeight, const std::string& containerType);
        

    virtual bool storeGoods(Goods* good) = 0;  // Lagrar en vara
    virtual void displayInfo() const = 0;  // Skriv ut info om containern

    float getMaxWeight() const;
    float getUsedWeight() const;
    std::string getContainerType() const;
};

#endif
