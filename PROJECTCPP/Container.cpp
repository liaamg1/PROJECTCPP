#include "Container.h"
#include "Goods.h"
#include <iostream>
#include "Food.h"
#include "Bulk.h"

Container::Container(double maxWeight)
    : maxWeight(maxWeight), currentWeight(0.0), itemCount(0) {
    // Initiera containern som tom
    for (int i = 0; i < 10; i++) {
        items[i] = nullptr;
    }
}



bool Container::canAddGoods(double weight) const {
    // Kontrollera att det finns tillräckligt med plats för den nya varan
    return (currentWeight + weight <= maxWeight);
}

void Container::addItem(Goods* goods) {
    if (canAddGoods(goods->getWeight()) && itemCount < 10) {
        if (itemCount == 0) {
            items[itemCount++] = goods;
            currentWeight += goods->getWeight();  // Lägg till vikten
        }
        else {
            bool compatible = false;
            for (int i = 0; i < itemCount; i++) {
                if ((dynamic_cast<Food*>(goods) && dynamic_cast<Food*>(items[i])) ||
                    (dynamic_cast<Bulk*>(goods) && dynamic_cast<Bulk*>(items[i]))) {
                    compatible = true;
                    break;
                }
            }

            if (compatible) {
                items[itemCount++] = goods;
                currentWeight += goods->getWeight();
            }
            else {
                std::cout << "Cannot add this item: Container already contains a different type!" << std::endl;
            }
        }
    }
    else {
        std::cout << "Cannot add item: Not enough space in the container." << std::endl;
    }
}

void Container::showContent() const {
    if (itemCount == 0) {
        std::cout << "Container is empty!" << std::endl;
        return;
    }

    double totalWeightUsed = 0.0;
    for (int i = 0; i < itemCount; i++) {
        Goods* item = items[i];
        if (item) {
            std::cout << "Item " << i + 1 << ": " << item->toString()
                << ", Weight: " << item->getWeight() << std::endl;
            totalWeightUsed += item->getWeight();
        }
    }

    double remainingWeight = maxWeight - totalWeightUsed;
    std::cout << "\nTotal weight used in container: " << totalWeightUsed << std::endl;
    std::cout << "Remaining weight capacity: " << remainingWeight << std::endl;
}

bool Container::isEmpty() const {
    return itemCount == 0;
}

double Container::getCurrentWeight() const {
    return currentWeight;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

Goods* Container::getItem(int index) const {
    if (index >= 0 && index < itemCount) {
        return items[index];
    }
    return nullptr;
}
