#ifndef CONTAINER_H
#define CONTAINER_H

#include <memory>
#include <stdexcept>

#include <exception>
#include <string>

#include "Food.h"
#include "Bulk.h"
#include "InvalidNameHelper.h"
//KOLLA HUR VI SKA GÖRA MED DENNA

class Container {
public:
    Container(double maxWeight);

    bool canAddGoods(double weight) const;
    void addItem(std::unique_ptr<Goods> goods);
    void showContent() const;
    bool isEmpty() const;

    double getCurrentWeight() const;
    double getMaxWeight() const;

    Goods* getItem(int index) const;

    
private:
    double maxWeight;
    double currentWeight;
    int itemCount;
    std::unique_ptr<Goods> items[100];
    bool isFirstItem;  // Flagga som håller koll på om vi har lagt till en vara och vad typen är
   
};

#endif
