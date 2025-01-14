#include "StorageSystem.h"

StorageSystem::StorageSystem() : containerCount(0) {
    for (int i = 0; i < 10; i++) {
        containers[i] = nullptr;
    }
}

StorageSystem::~StorageSystem() {
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
    if (goods->getName().empty() || !InvalidNameException::isValidName(goods->getName())) {
        std::cout << "Invalid product name, cannot add item!" << std::endl;
        return false;
    }
    for (int i = 0; i < containerCount; i++) {
        bool isFirstItemBulk = dynamic_cast<Bulk*>(containers[i]->getItem(0)) != nullptr;

        if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
            if (containers[i]->canAddGoods(goods->getWeight())) {
                containers[i]->addItem(std::move(goods));
                added = true;
                break;
            }
        }
        else if (!isFirstItemBulk && dynamic_cast<Food*>(goods.get())) {
            if (containers[i]->canAddGoods(goods->getWeight())) {
                containers[i]->addItem(std::move(goods));
                added = true;
                break;
            }
        }
    }

    if (!added) {
        if (containerCount < 10) {
            if (dynamic_cast<Bulk*>(goods.get())) {
                
                double maxWeight = 200.0;
                double maxVolume = 300.0;
                containers[containerCount] = std::make_unique<Container>(maxWeight, maxVolume);
                containers[containerCount]->addItem(std::move(goods));
                added = true;
            }
            else if (dynamic_cast<Food*>(goods.get())) {
                
                double maxWeight = 200.0;
                containers[containerCount] = std::make_unique<Container>(maxWeight);
                containers[containerCount]->addItem(std::move(goods));
                added = true;
            }
            containerCount++;
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
        containers[i]->showContent();
    }
}
