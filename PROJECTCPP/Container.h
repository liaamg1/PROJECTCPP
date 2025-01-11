#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <stdexcept>
#include <exception>
#include <string>
#include "GoodsHandler.h"
#include "Food.h"
#include "Bulk.h"
#include "InvalidNameException.h"

static const int CAP = 100;
class Container {
private:
    double maxWeight;
    double currentWeight;
    int itemCount;
    std::unique_ptr<Goods> items[CAP];
    bool isFirstItem;  // Flagga som h�ller koll p� om vi har lagt till en vara och vad typen �r

public:
    Container(double maxWeight);

    bool canAddGoods(double weight) const;
    void addItem(std::unique_ptr<Goods> goods);
    void showContent() const;
    bool isEmpty() const;

    double getCurrentWeight() const;
    double getMaxWeight() const;

    Goods* getItem(int index) const;

   
};

#endif
