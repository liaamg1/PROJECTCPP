#pragma once
#include "Goods.h"
#include "Food.h"
#include "Bulk.h"
#include <iostream>

class Container {
private:
    Goods* item;         // Den vara som finns i containern
    double maxWeight;    // Max vikt f�r containern
    double currentWeight; // Aktuell vikt i containern

public:
    Container(double maxWeight);       // Konstruktor
    void showContent() const;          // Visa inneh�llet i containern
    double getCurrentWeight() const;   // H�mta aktuell vikt
    double getMaxWeight() const;       // H�mta max vikt
    Goods* getItem();
    void setItem(Goods* newItem);
    // H�mta varan i containern (icke-const)
    bool isEmpty() const;              // Kontrollera om containern �r tom
    bool canAddGoods(double weight) const; // Kontrollera om varan kan l�ggas till
};
