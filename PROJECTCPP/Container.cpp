#include "Container.h"

Container::Container(double maxWeight)
    : maxWeight(maxWeight), currentWeight(0.0), isFirstItem(false) {
    
}

bool Container::canAddGoods(double weight) const {
    return (currentWeight + weight <= maxWeight);
}

void Container::addItem(std::unique_ptr<Goods> goods) {
    try {
        // EXCEPTION
        if (goods->getName().empty() || !InvalidNameException::isValidName(goods->getName())) {
            throw InvalidNameException();
        }

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
    catch (const InvalidNameException& e) {
        std::cout << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "General error: " << e.what() << std::endl;
    }
}

void Container::showContent() const {
    if (items.empty()) {
        std::cout << "Container is empty!" << std::endl;
        return;
    }

    double totalWeightUsed = 0.0;
    for (size_t i = 0; i < items.size(); ++i) {
        if (items[i]) {
            std::cout << "Item " << i + 1 << ": " << items[i]->toString()<< std::endl;
            totalWeightUsed += items[i]->getWeight();
        }
    }

    double remainingWeight = maxWeight - totalWeightUsed;
    std::cout << "\nTotal weight used in container: " << totalWeightUsed << std::endl;
    std::cout << "Remaining weight capacity: " << remainingWeight <<"\n"<< std::endl;
}

bool Container::isEmpty() const {
    return items.empty();
}

double Container::getCurrentWeight() const {
    return currentWeight;
}

double Container::getMaxWeight() const {
    return maxWeight;
}

Goods* Container::getItem(int index) const {
    if (index >= 0 && index < static_cast<int>(items.size())) {
        return items[index].get();  
    }
    return nullptr;
}
