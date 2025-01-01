#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include <iostream>

Container::Container(double maxWeight) : item(nullptr), maxWeight(maxWeight), currentWeight(0.0) {}

bool Container::addGoods(Goods* aGoods) {
    // Om containern är tom, kan vi lägga till varan
    if (item == nullptr) {
        item = aGoods;  // Sätt varan i containern
        currentWeight = aGoods->getWeight();  // Sätt vikten på containern
        return true;
    }

    // Om containern redan har en vara, kontrollera om det är samma typ av vara
    if ((dynamic_cast<Food*>(item) && dynamic_cast<Food*>(aGoods)) ||
        (dynamic_cast<Bulk*>(item) && dynamic_cast<Bulk*>(aGoods))) {
        if (currentWeight + aGoods->getWeight() <= maxWeight) {
            currentWeight += aGoods->getWeight();  // Lägg till vikten till containern
            return true;
        }
        else {
            std::cout << "Container exceeds max weight!" << std::endl;
        }
    }
    else {
        std::cout << "Container already contains a different type of goods!" << std::endl;
    }

    return false;
}

void Container::showContent() const {
    if (item != nullptr) {
        // Om containern har en vara, skriv ut den
        std::cout << "Container holds: " << item->toString() << ", Current weight: " << currentWeight << std::endl;

        // Här kontrollerar vi om det är Food eller Bulk, och skriver ut relevant information
        Food* foodItem = dynamic_cast<Food*>(item);
        Bulk* bulkItem = dynamic_cast<Bulk*>(item);

        if (foodItem != nullptr) {
            // Om varan är av typen Food, skriv ut antal och vikt
            std::cout << "Item: " << foodItem->getName()
                << ", Quantity: " << foodItem->getQuantity()
                << ", Weight: " << foodItem->getWeight() << std::endl;
        }
        else if (bulkItem != nullptr) {
            // Om varan är av typen Bulk, skriv ut mängd och vikt
            std::cout << "Item: " << bulkItem->getName()
                << ", Volume: " << bulkItem->getVolume()
                << ", Weight: " << bulkItem->getWeight() << std::endl;
        }
    }
    else {
        std::cout << "Container is empty!" << std::endl;
    }

    // Beräkna total vikt använd och total vikt kvar
    double totalWeightUsed = currentWeight;
    double remainingWeight = maxWeight - currentWeight;

    std::cout << "\nTotal weight used in container: " << totalWeightUsed << std::endl;
    std::cout << "Remaining weight capacity: " << remainingWeight << std::endl;
}


double Container::getCurrentWeight() const {
    return currentWeight;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

Goods* Container::getItem() const {   
    return item;  // Returnerar varan som finns i containern
}
