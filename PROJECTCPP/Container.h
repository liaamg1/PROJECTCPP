#pragma once
#include "Goods.h"
#include "Food.h"
#include "Bulk.h"
#include <iostream>

class Container {
private:
    Goods* item;         // Den vara som finns i containern
    double maxWeight;    // Max vikt för containern
    double currentWeight; // Aktuell vikt i containern

public:
    Container(double maxWeight);       // Konstruktor
    void showContent() const;          // Visa innehållet i containern
    double getCurrentWeight() const;   // Hämta aktuell vikt
    double getMaxWeight() const;       // Hämta max vikt
    Goods* getItem();
    void setItem(Goods* newItem);
    // Hämta varan i containern (icke-const)
    bool isEmpty() const;              // Kontrollera om containern är tom
    bool canAddGoods(double weight) const; // Kontrollera om varan kan läggas till
};
