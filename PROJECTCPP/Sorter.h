#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <functional>
#include <string>
#include <vector>  // L�gg till <vector> f�r dynamisk lagring

template <typename T>
class Sorter {
private:
    std::vector<T*> items;  // Anv�nd vector ist�llet f�r statisk array

public:
    // Konstruktor
    Sorter();

    // L�gg till ett objekt till Sorter
    bool addItem(T* item);

    // Sortera objekten
    void sortItems(std::function<bool(const T*, const T*)> comparer);

    // Visa objekten
    void showItems() const;
};

#endif
