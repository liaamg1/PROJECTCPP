#ifndef FOOD_H
#define FOOD_H
#include "Goods.h"

class Food : public Goods
{
private:
    int quantity;

public:
    Food(int quantity = 0, float weight = 0.0f, const std::string& name = "Unknown");  // Initialisera quantity till 0
    ~Food(); // Destruktor
    void setQuantity(int quantity);  // Setter f�r quantity
    int getQuantity() const;  // Getter f�r quantity
    std::string toString() const override;

    // Ber�kna quantity baserat p� weight
    //void calculateQuantityBasedOnWeight(float weightPerUnit);
};

#endif // !FOOD_H
