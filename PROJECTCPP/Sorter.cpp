#include "Sorter.h"
#include "Food.h"
#include "Bulk.h"
#include <algorithm>

// Konstruktor
template <typename T>
Sorter<T>::Sorter() {
    // Ingen initialisering behövs längre för vector
}

// Lägg till ett objekt till Sorter
template <typename T>
bool Sorter<T>::addItem(T* item) {
    items.push_back(item);  // Lägg till objektet i vectorn
    return true;
}

// Sortera objekten
template <typename T>
void Sorter<T>::sortItems(std::function<bool(const T*, const T*)> comparing) {
    std::sort(items.begin(), items.end(), comparing);  // Sortera via vectorns begin() och end()
}

// Visa objekten
template <typename T>
void Sorter<T>::showItems() const {
    for (const auto& item : items) {  // Iterera över vectorn
        if (item != nullptr) {
            std::cout << item->toString() << std::endl;
        }
    }
}

// Explicit instansiering av Sorter-klasser
template class Sorter<Goods>;
template class Sorter<Food>;
template class Sorter<Bulk>;
