#include "Container.h"
#include "Goods.h"
#include <iostream>
#include "Food.h"
#include "Bulk.h"
#include "InvalidNameHelper.h"

Container::Container(double maxWeight)
    : maxWeight(maxWeight), currentWeight(0.0), itemCount(0), isFirstItem(false) {

    for (int i = 0; i < 10; i++) {
        items[i] = nullptr; 
    }
}

bool Container::canAddGoods(double weight) const {
    return (currentWeight + weight <= maxWeight);
}

void Container::addItem(std::unique_ptr<Goods> goods) {
    try {
        //EXCEPTION, 1P
        if (goods->getName().empty() || !InvalidNameException::isValidName(goods->getName())) {
            throw InvalidNameException(); 
        }
        // KOLLA S� INTE MINDRE �N 0
       
        if (itemCount == 0) {
            items[itemCount++] = std::move(goods);
            currentWeight += items[itemCount - 1]->getWeight();
        }
        else {
            
            bool isFirstItemBulk = dynamic_cast<Bulk*>(items[0].get()) != nullptr;
            Bulk* bulkPtr = dynamic_cast<Bulk*>(items[0].get());
           
            if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
                if (canAddGoods(goods->getWeight()) && itemCount < 10) {
                    items[itemCount++] = std::move(goods);
                    currentWeight += items[itemCount - 1]->getWeight();
                }
                else {
                    std::cout << "Cannot add item: Not enough space in the container." << std::endl;
                }
            }
           
            else if (!isFirstItemBulk && dynamic_cast<Food*>(goods.get())) {
                if (canAddGoods(goods->getWeight()) && itemCount < 10) {
                    items[itemCount++] = std::move(goods);
                    currentWeight += items[itemCount - 1]->getWeight();
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
    if (itemCount == 0) {
        std::cout << "Container is empty!" << std::endl;
        return;
    }

    double totalWeightUsed = 0.0;
    for (int i = 0; i < itemCount; i++) {
        if (items[i]) {
            std::cout << "Item " << i + 1 << ": " << items[i]->toString()
                << ", Weight: " << items[i]->getWeight() << std::endl;
            totalWeightUsed += items[i]->getWeight();
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
        return items[index].get();  
    }
    return nullptr;
}
