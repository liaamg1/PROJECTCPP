#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <iostream>
#include <string>
const int MAX_GOODS = 100;
class Container {
private:
    float maxWeight;  // Maxvikt
    float usedWeight; // Använd vikt
    std::string containerType;  // Typ av container (Bulk, Food, etc.)
    int foodCount;
    Goods* foodGoods[MAX_GOODS];  // Array för att lagra Food-varor
public:
    Container(float maxWeight, const std::string& containerType);
        
    float getMaxWeight() const;
    float getUsedWeight() const;
    std::string getContainerType() const;
    bool storeFood(Goods* food);
    
    void displayInfo() const;
};

#endif
