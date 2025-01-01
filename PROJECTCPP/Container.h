#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include "Bulk.h"
#include "Food.h"

class Container {
private:
    Goods* item;  // Varan som lagras i containern (kan vara Food eller Bulk)
    double maxWeight;  // Max vikt containern kan hålla
    double currentWeight;  // Nuvarande vikt av varan i containern

public:
    Container(double maxWeight);
    Goods* getItem() const;
    bool addGoods(Goods* aGoods);
    void showContent() const;
    double getCurrentWeight() const;
    double getMaxWeight() const;
};

#endif // CONTAINER_H
