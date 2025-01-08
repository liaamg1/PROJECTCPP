#include "Container.h"
#include "Goods.h"
#include <iostream>
#include "Food.h"
#include "Bulk.h"

Container::Container(double maxWeight)
    : maxWeight(maxWeight), currentWeight(0.0), itemCount(0) {
    // Initiera containern som tom
    for (int i = 0; i < 10; i++) {
        items[i] = nullptr;  // Sätt alla pekare till nullptr
    }
}

bool Container::canAddGoods(double weight) const {
    // Kontrollera att det finns tillräckligt med plats för varan
    return (currentWeight + weight <= maxWeight);
}

void Container::addItem(std::unique_ptr<Goods> goods) {
    try {
        if (goods->getName().empty() || !isValidName(goods->getName())) {
            throw InvalidNameException(); //EXCEPTION, 1P
        }

        // Om containern är tom, acceptera varan oavsett typ
        if (itemCount == 0) {
            items[itemCount++] = std::move(goods);
            currentWeight += items[itemCount - 1]->getWeight();
        }
        else {
            // Om den första varan är av typ Bulk
            bool isFirstItemBulk = dynamic_cast<Bulk*>(items[0].get()) != nullptr;
            Bulk* bulkPtr = dynamic_cast<Bulk*>(items[0].get());
            // Om den första varan är en Bulk, acceptera bara Bulk-varor
            if (isFirstItemBulk && dynamic_cast<Bulk*>(goods.get())) {
                if (canAddGoods(goods->getWeight()) && itemCount < 10) {
                    items[itemCount++] = std::move(goods);
                    currentWeight += items[itemCount - 1]->getWeight();
                }
                else {
                    std::cout << "Cannot add item: Not enough space in the container." << std::endl;
                }
            }
            // Om den första varan inte är en Bulk, skapa en ny container för Food
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

bool Container::isValidName(const std::string& name) const {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {  // Tillåter bara bokstäver och mellanslag
            return false;
        }
    }
    return true;
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
        return items[index].get();  // Returnera en pekare till objektet
    }
    return nullptr;
}
