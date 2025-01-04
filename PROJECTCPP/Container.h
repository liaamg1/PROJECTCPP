#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <iostream>

class Container {
private:
    Goods* items[10];  // Array f�r att h�lla upp till 10 objekt i containern
    int itemCount;
    double maxWeight;
    double currentWeight;
    bool hasFood;   // Flagga f�r att kontrollera om containern har Food
    bool hasBulk;   // Flagga f�r att kontrollera om containern har Bulk

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
