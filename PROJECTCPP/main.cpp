#include <iostream>
#include "Goods.h"
#include "Bulk.h"
#include "Food.h"
int main() {
    Bulk bulkItem;
    

    bulkItem.setWeight(15.5f);  // S�tt vikt till 15.5
    bulkItem.setName("Gravel");  // S�tt namn till "Heavy Bulk Item"
    bulkItem.setType("Bulk");  // S�tt typ till "Type A"
    bulkItem.setVolume(1000);
    bulkItem.displayInfo();
    std::cout << std::endl;
    std::cout << std::endl;

    Food foodItem;

    foodItem.setWeight(100);
    foodItem.setName("Meat");
    foodItem.setType("Food");
    foodItem.setQuantity(3);
    foodItem.displayInfo();





}