#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include <iostream>

Container::Container(double maxWeight) : item(nullptr), maxWeight(maxWeight), currentWeight(0.0) {}

void Container::showContent() const {
    if (item != nullptr) {
        std::cout << "Container holds: " << item->toString() << ", Current weight: " << currentWeight << std::endl;

        Food* foodItem = dynamic_cast<Food*>(item);
        Bulk* bulkItem = dynamic_cast<Bulk*>(item);

        if (foodItem != nullptr) {
            std::cout << "Item: " << foodItem->getName()
                << ", Quantity: " << foodItem->getQuantity()
                << ", Weight: " << foodItem->getWeight() << std::endl;
        }
        else if (bulkItem != nullptr) {
            std::cout << "Item: " << bulkItem->getName()
                << ", Volume: " << bulkItem->getVolume()
                << ", Weight: " << bulkItem->getWeight() << std::endl;
        }
    }
    else {
        std::cout << "Container is empty!" << std::endl;
    }

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

// Nu returneras ett icke-const pekare, så att vi kan modifiera innehållet
Goods* Container::getItem() {
    return item;
}

bool Container::isEmpty() const {
    return item == nullptr;
}

bool Container::canAddGoods(double weight) const {
    return currentWeight + weight <= maxWeight;
}
void Container::setItem(Goods* newItem) {
    item = newItem;
}
