#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <stdexcept>
#include <exception>
#include <string>
#include <vector>  
#include "GoodsHandler.h"
#include "Food.h"
#include "Bulk.h"
#include "InvalidNameException.h"

class Container {
private:
    double maxWeight;
    double currentWeight;

    std::vector<std::unique_ptr<Goods>> items; 
    float maxVolume;

    bool isFirstItem;

public:

    Container(double maxWeight);
    Container(double maxWeight, float maxVolume);

    bool canAddGoods(double weight, double volume) const;
    bool canAddGoods(double weight) const;
    void addItem(std::unique_ptr<Goods> goods);
    void showContent() const;
    bool isEmpty() const;

    double getCurrentWeight() const;
    double getMaxWeight() const;
    double getMaxVolume() const;
    Goods* getItem(int index) const;
};

#endif
