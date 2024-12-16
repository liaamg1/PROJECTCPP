#include <iostream>
#include "Container.h"
#include "Goods.h"
#include "Bulk.h"
#include "Food.h"

int main() {
    

    // Skapa Bulk vara
    Bulk bulkGood;
    bulkGood.setType("Bulk");
    bulkGood.setName("Bulk Item");
    bulkGood.setWeight(200.0f);  // 200 kg
    bulkGood.setVolume(2.0f);    // 2 m3

    // Skapa Food vara
    Food foodGood;
    foodGood.setType("Food");
    foodGood.setName("Food Item");
    foodGood.setWeight(1.0f);  // 1 kg per enhet
    foodGood.setQuantity(50);  // 50 enheter

    foodGood.displayInfo();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    bulkGood.displayInfo();
}
