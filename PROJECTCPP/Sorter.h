
#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <functional>
#include <string>

template <typename T>
class Sorter {
private:
    static const std::size_t MAX_ITEMS = 100;  
    T* items[MAX_ITEMS];  
    std::size_t size;     

public:
   
    Sorter();

   
    bool addItem(T* item);

    
    void sortItems(std::function<bool(const T*, const T*)> comparer);

   
    void showItems() const;

    
};

#endif 
