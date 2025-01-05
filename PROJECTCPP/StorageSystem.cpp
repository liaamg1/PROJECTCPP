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

    // F�rs�k att l�gga till varan i en passande container
    for (int i = 0; i < containerCount; i++) {
        // Kolla om f�rsta varan i containern �r av samma typ
        bool isFirstItemBulk = dynamic_cast<Bulk*>(containers[i]->getItem(0)) != nullptr;

        if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
            // L�gg till varan i containern om den f�r plats
            if (containers[i]->canAddGoods(goods->getWeight())) {
                containers[i]->addItem(std::move(goods));
                added = true;
                break;
            }
        }
        else if (!isFirstItemBulk && dynamic_cast<Food*>(goods.get())) {
            // L�gg till varan i containern om den f�r plats
            if (containers[i]->canAddGoods(goods->getWeight())) {
                containers[i]->addItem(std::move(goods));
                added = true;
                break;
            }
        }
    }

    // Om ingen passande container hittades, skapa en ny container
    if (!added) {
        if (containerCount < 10) {
            // Skapa en ny container baserat p� varans typ (Bulk eller Food)
            if (dynamic_cast<Bulk*>(goods.get())) {
                addContainer(100.0);  // Skapa en container f�r Bulk med en maxvikt
            }
            else {
                addContainer(50.0);  // Skapa en container f�r Food med en annan maxvikt
            }
            containers[containerCount - 1]->addItem(std::move(goods));  // L�gg till varan i den nya containern
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
