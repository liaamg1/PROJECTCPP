#include "StorageSystem.h"
#include <iostream>
#include "Food.h"
#include "Bulk.h"
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

bool StorageSystem::addGoods(Goods* goods) {
    // Försök att lägga till varan i en container
    for (int i = 0; i < containerCount; i++) {
        if (containers[i]->isEmpty() ||
            (dynamic_cast<Food*>(containers[i]->getItem()) && dynamic_cast<Food*>(goods)) ||
            (dynamic_cast<Bulk*>(containers[i]->getItem()) && dynamic_cast<Bulk*>(goods))) {

            // Kolla om containern kan ta emot varan baserat på vikten
            if (containers[i]->canAddGoods(goods->getWeight())) {
                // Lägg till varan i containern
                containers[i]->setItem(goods); // Nu fungerar detta för att sätta varan
                return true;
            }
        }
    }

    // Om ingen passande container hittas, skapa en ny container och lägg till varan
    if (containerCount < 10) {
        addContainer(100.0);  // Skapa en ny container med maxvikt 100.0 (eller lämplig vikt)
        containers[containerCount - 1]->setItem(goods);  // Lägg till varan i den nya containern
        return true;
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
