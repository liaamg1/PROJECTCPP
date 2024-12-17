#include <iostream>
#include "Container.h"
#include "Food.h"

int main() {
    // Skapa en container med en maxvikt på 10.0 kg
    Container foodContainer(10.0f, "FoodContainer");

    // Skapa några food-objekt
    Food apple(3, 0.2f, "Food", "Apple");     // 0.2 kg per äpple
    Food cucumber(2, 0.5f, "Food", "Cucumber");  // 0.5 kg per gurka
    Food cucumber1(2, 10.0f, "Food", "Cucumber");

    foodContainer.storeFood(&apple);
    foodContainer.storeFood(&cucumber);
    foodContainer.storeFood(&cucumber1);
    foodContainer.displayInfo();

    return 0;
}
