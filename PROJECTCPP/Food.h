#ifndef FOOD_H
#define FOOD_H
#include "Goods.h"

class Food : public Goods
{
private:
    int quantity;

public:
    Food(int quantity = 0, float weight, const std::string& type = "Food", const std::string& name);  // Initialisera quantity till 0
    ~Food(); // Destrukt�r
    void displayInfo() const;  // Metod f�r att visa information om matvaran
    void setQuantity(int quantity);  // Setter f�r quantity
    int getQuantity() const override;  // Getter f�r quantity

    // Ber�kna quantity baserat p� weight
    //void calculateQuantityBasedOnWeight(float weightPerUnit);
};

#endif // !FOOD_H
