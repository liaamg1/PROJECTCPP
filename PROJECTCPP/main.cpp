#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
int main() {

    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    // Skapa en container med en maxvikt på 10.0 kg
    Container foodContainer(10.0f, "FoodContainer");
    Container bulkContainer(10.0f, "BulkContainer");
    // Skapa några food-objekt
    Food apple(3, 0.2f, "Food", "Apple");     
    Food cucumber(2, 0.5f, "Food", "Cucumber"); 
    Food cucumber1(2, 10.0f, "Food", "Cucumber");
    Bulk gravel(1, 7.0f, "Bulk", "Gravel");

    foodContainer.storeFood(&apple);
    foodContainer.storeFood(&cucumber);
    foodContainer.storeFood(&cucumber1);
    bulkContainer.storeBulk(&gravel);
    foodContainer.displayInfo();
    std::cout << std::endl;
    std::cout << std::endl;
    gravel.toString();
    std::cout << std::endl;
    std::cout << std::endl;
    bulkContainer.displayInfo();
    std::cout << std::endl;
    std::cout << std::endl;
    return 0;
}
