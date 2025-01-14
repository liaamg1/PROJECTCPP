#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <functional>
#include <string>
#include <vector>  

template <typename T>
class Sorter {
private:
    std::vector<T*> items;  

public:
   
    Sorter();

   
    bool addItem(T* item);

    
    void sortItems(std::function<bool(const T*, const T*)> comparer);

    
    void showItems() const;
};

#endif
