#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <iostream>

class Container {
private:
    Goods* items[10];  // Array för att hålla upp till 10 objekt i containern
    int itemCount;
    double maxWeight;
    double currentWeight;
   

public:
    Container(double maxWeight);
    
    bool canAddGoods(double weight) const;
    void addItem(Goods* goods);
    void showContent() const;
    bool isEmpty() const;
    double getCurrentWeight() const;
    double getMaxWeight() const;
    Goods* getItem(int index) const;
};

#endif
