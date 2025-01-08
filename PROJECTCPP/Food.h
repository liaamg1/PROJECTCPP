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
    void setQuantity(int quantity);  // Setter för quantity
    int getQuantity() const;  // Getter för quantity
    std::string toString() const override;

    // Beräkna quantity baserat på weight
    //void calculateQuantityBasedOnWeight(float weightPerUnit);
};

#endif // !FOOD_H
