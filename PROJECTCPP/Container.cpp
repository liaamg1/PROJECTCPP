#include "Container.h"

Container::Container(double maxWeight)
    : maxWeight(maxWeight), currentWeight(0.0), isFirstItem(false), maxVolume(0.0f) {
    
}
Container::Container(double maxWeight, float maxVolume)
    : maxWeight(maxWeight), currentWeight(0.0), maxVolume(maxVolume), isFirstItem(false) {
}
bool Container::canAddGoods(double weight) const {
    return (currentWeight + weight <= maxWeight);
}

void Container::addItem(std::unique_ptr<Goods> goods) {

    if (items.empty()) {
        items.push_back(std::move(goods));
        currentWeight += items.back()->getWeight();
    }
    else {
        bool isFirstItemBulk = dynamic_cast<Bulk*>(items[0].get()) != nullptr;
        if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
            if (canAddGoods(goods->getWeight())) {
                items.push_back(std::move(goods));
                currentWeight += items.back()->getWeight();
            }
            else {
                std::cout << "Cannot add item: Not enough space in the container." << std::endl;
            }
        }
        else if (!isFirstItemBulk && dynamic_cast<Food*>(goods.get())) {
            if (canAddGoods(goods->getWeight())) {
                items.push_back(std::move(goods));
                currentWeight += items.back()->getWeight();
            }
            else {
                std::cout << "Cannot add item: Not enough space in the container." << std::endl;
            }
        }
        else {
            std::cout << "Type mismatch, creating a new container for the item." << std::endl;
        }
    }
}
    

void Container::showContent() const {
    if (items.empty()) {
        std::cout << "Container is empty!" << std::endl;
        return;
    }

    double totalWeightUsed = 0.0;
    double totalVolumeUsed = 0.0;

    for (int i = 0; i < items.size(); ++i) {
        if (items[i]) {
            std::cout << "Item " << i + 1 << ": " << items[i]->toString()<< std::endl;
            totalWeightUsed += items[i]->getWeight();
            if (dynamic_cast<Bulk*>(items[i].get())) {
                totalVolumeUsed += dynamic_cast<Bulk*>(items[i].get())->getVolume();
            }
        }
    }

    double remainingWeight = maxWeight - totalWeightUsed;
    std::cout << "\nTotal weight used in container: " << totalWeightUsed << std::endl;
    std::cout << "Remaining weight capacity: " << remainingWeight <<"\n"<< std::endl;
    if (maxVolume > 0) {
        double remainingVolume = maxVolume - totalVolumeUsed;
        std::cout << "Total volume used in container: " << totalVolumeUsed << std::endl;
        std::cout << "Remaining volume capacity: " << remainingVolume << "\n" << std::endl;
    }
}

bool Container::canAddGoods(double weight, double volume) const {
    return (currentWeight + weight <= maxWeight && volume <= maxVolume);
}
bool Container::isEmpty() const {
    return this->items.empty();
}

double Container::getCurrentWeight() const {
    return this->currentWeight;
}

double Container::getMaxWeight() const {
    return this->maxWeight;
}

double Container::getMaxVolume() const
{
    return this->maxVolume;
}

Goods* Container::getItem(int index) const {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        return items[index].get();  
    }
    return nullptr;
}
