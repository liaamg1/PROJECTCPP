#include "StorageSystem.h"
#include <iostream>

StorageSystem::StorageSystem() : containerCount(0) {
    for (int i = 0; i < 10; i++) {
        containers[i] = nullptr;
    }
}

StorageSystem::~StorageSystem() {
    for (int i = 0; i < containerCount; i++) {
        delete containers[i];
    }
}

bool StorageSystem::addContainer(double maxWeight) {
    if (containerCount >= 10) {
        std::cout << "Maximum number of containers reached!" << std::endl;
        return false;
    }
    containers[containerCount] = new Container(maxWeight);
    containerCount++;
    return true;
}

bool StorageSystem::addGoodsToContainer(Goods* goods) {
    // F�rs�k att l�gga till varan i en container
    for (int i = 0; i < containerCount; i++) {
        // Om containern �r tom, eller om b�de containern och varan �r av samma typ
        if (containers[i]->getItem() == nullptr ||
            // Om containern och varan b�da �r av typen Food
            (dynamic_cast<Food*>(containers[i]->getItem()) && dynamic_cast<Food*>(goods)) ||
            // Om containern och varan b�da �r av typen Bulk
            (dynamic_cast<Bulk*>(containers[i]->getItem()) && dynamic_cast<Bulk*>(goods))) {
            if (containers[i]->addGoods(goods)) {
                return true;
            }
        }
    }

    // Om ingen passande container hittas, skapa en ny container
    if (containerCount < 10) {
        addContainer(100.0);  // Eller n�got maxvikt som passar
        return containers[containerCount - 1]->addGoods(goods);
    }

    std::cout << "No suitable container available!" << std::endl;
    return false;
}


void StorageSystem::showAllContainers() const {
    for (int i = 0; i < containerCount; i++) {
        std::cout << "Container " << i + 1 << ": ";
        containers[i]->showContent();
    }
}
