#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <functional>
#include <string>
#include <vector>  // Lägg till <vector> för dynamisk lagring

template <typename T>
class Sorter {
private:
    std::vector<T*> items;  // Använd vector istället för statisk array

public:
    // Konstruktor
    Sorter();

    // Lägg till ett objekt till Sorter
    bool addItem(T* item);

    // Sortera objekten
    void sortItems(std::function<bool(const T*, const T*)> comparer);

    // Visa objekten
    void showItems() const;
};

#endif
