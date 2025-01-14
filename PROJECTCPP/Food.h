#ifndef FOOD_H
#define FOOD_H
#include "Goods.h"

class Food : public Goods
{
private:
    int quantity;

public:
    Food(int quantity = 0, float weight = 0.0f, const std::string& name = "Unknown");  
    ~Food(); 
    void setQuantity(int quantity);  
    int getQuantity() const;  
    std::string toString() const override;
};
#endif // !FOOD_H
