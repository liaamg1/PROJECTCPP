#include "Sorter.h"
#include "Food.h"
#include "Bulk.h"
#include <algorithm>

// Konstruktor
template <typename T>
Sorter<T>::Sorter() {
}


template <typename T>
bool Sorter<T>::addItem(T* item) {
    items.push_back(item); 
    return true;
}

// Sortera objekten
template <typename T>
void Sorter<T>::sortItems(std::function<bool(const T*, const T*)> comparing) {
    std::sort(items.begin(), items.end(), comparing);  
}

// Visa objekten
template <typename T>
void Sorter<T>::showItems() const {
    for (const auto& item : items) {  
        if (item != nullptr) {
            std::cout << item->toString() << std::endl;
        }
    }
}

template class Sorter<Goods>;
template class Sorter<Food>;
template class Sorter<Bulk>;
