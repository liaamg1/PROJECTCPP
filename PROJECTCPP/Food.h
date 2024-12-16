#ifndef FOOD_H
#define FOOD_H
#include "Goods.h"

class Food : public Goods
{
private:
    int quantity;

public:
    Food();  // Konstruktor
    ~Food(); // Destruktör
    void displayInfo() const;  // Metod för att visa information om matvaran
    void setQuantity(int quantity);  // Setter för quantity
    int getQuantity() const override;  // Getter för quantity

    // Beräkna quantity baserat på weight
    //void calculateQuantityBasedOnWeight(float weightPerUnit);
};

#endif // !FOOD_H
