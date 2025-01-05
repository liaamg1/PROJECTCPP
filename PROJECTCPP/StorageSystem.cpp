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
    // Radera alla containrar n�r StorageSystem f�rst�rs
    for (int i = 0; i < containerCount; i++) {
        std::cout << "Destroying Container" << std::endl;
        delete this->containers[i];
    }
}

bool StorageSystem::addContainer(double maxWeight) {
    if (containerCount < 10) {
        containers[containerCount] = new Container(maxWeight);
        containerCount++;
        return true;
    }
    std::cout << "Maximum number of containers reached!" << std::endl;
    return false;
}

bool StorageSystem::addGoods(Goods* goods) {
    bool added = false;

    // F�rs�k att l�gga till varan i en passande container
    for (int i = 0; i < containerCount; i++) {
        if (containers[i]->canAddGoods(goods->getWeight())) {
            containers[i]->addItem(goods);  // L�gg till varan i containern
            added = true;
            break;  // N�r varan har lagts till, avsluta loopen
        }
    }

    // Om ingen passande container hittades, skapa en ny container och l�gg till varan d�r
    if (!added) {
        if (containerCount < 10) {
            addContainer(100.0);  // Skapa en ny container med maxvikt 100.0
            containers[containerCount - 1]->addItem(goods);  // L�gg till varan i den nya containern
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
