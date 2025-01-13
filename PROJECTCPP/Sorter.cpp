
#include "Sorter.h"
#include "Food.h"  
#include "Bulk.h"  
#include <algorithm> 

// Konstruktor
template <typename T>
Sorter<T>::Sorter() : size(0) {
    for (std::size_t i = 0; i < MAX_ITEMS; ++i) {
        items[i] = nullptr;
    }
}

// Lägg till ett objekt till Sorter
template <typename T>
bool Sorter<T>::addItem(T* item) {
    if (size < MAX_ITEMS) {
        items[size++] = item;
        return true;
    }
    std::cout << "Error: Cannot add more items, array is full." << std::endl;
    return false;
}

// Sortera objekten
template <typename T>
void Sorter<T>::sortItems(std::function<bool(const T*, const T*)> comparer) {
    std::sort(items, items + size, comparer);
}

// Visa objekten
template <typename T>
void Sorter<T>::showItems() const {
    for (std::size_t i = 0; i < size; ++i) {
        if (items[i] != nullptr) {
            std::cout << items[i]->toString() << std::endl;
        }
    }
}


template class Sorter<Goods>;
template class Sorter<Food>;
template class Sorter<Bulk>;
