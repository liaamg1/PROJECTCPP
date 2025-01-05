#include "StorageSystem.h"
#include <iostream>
#include "Food.h"
#include "Bulk.h"

StorageSystem::StorageSystem() : containerCount(0) {
    // Initiera containrarna som nullptr
    for (int i = 0; i < 10; i++) {
        containers[i] = nullptr;
    }
}

StorageSystem::~StorageSystem() {
    // Radera alla containrar när StorageSystem förstörs
    for (int i = 0; i < containerCount; i++) {
        std::cout << "Destroying Container" << std::endl;
    }
}

bool StorageSystem::addContainer(double maxWeight) {
    if (containerCount < 10) {
        containers[containerCount] = std::make_unique<Container>(maxWeight);
        containerCount++;
        return true;
    }
    std::cout << "Maximum number of containers reached!" << std::endl;
    return false;
}

bool StorageSystem::addGoods(std::unique_ptr<Goods> goods) {
    bool added = false;

    // Försök att lägga till varan i en passande container
    for (int i = 0; i < containerCount; i++) {
        bool isFirstItemBulk = dynamic_cast<Bulk*>(containers[i]->getItem(0));

        if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
            containers[i]->addItem(std::move(goods));
            added = true;
            break;
        }
        else if (!isFirstItemBulk && dynamic_cast<Food*>(goods.get())) {
            containers[i]->addItem(std::move(goods));
            added = true;
            break;
        }
    }

    // Om ingen passande container hittades, skapa en ny container och lägg till varan där
    if (!added) {
        if (containerCount < 10) {
            addContainer(100.0);  // Skapa en ny container med maxvikt 100.0
            containers[containerCount - 1]->addItem(std::move(goods));  // Lägg till varan i den nya containern
            added = true;
        }
        else {
            std::cout << "No suitable container available!" << std::endl;
        }
    }

    return added;
}

void StorageSystem::showAllContainers() const {
    for (int i = 0; i < containerCount; i++) {
        std::cout << "Container " << i + 1 << " contains the following items:" << std::endl;
        containers[i]->showContent();  // Visa alla varor i containern
    }
}
