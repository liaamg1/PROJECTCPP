#ifndef STORAGE_SYSTEM_H
#define STORAGE_SYSTEM_H

#include "Container.h"


class StorageSystem {
public:
    
    StorageSystem();
    ~StorageSystem();

    
    bool addContainer(double maxWeight);

   
    bool addGoods(std::unique_ptr<Goods> goods);

    
    void showAllContainers() const;

private:
    static const int MAX_CONTAINERS = 10; 

    std::unique_ptr<Container> containers[MAX_CONTAINERS];  


    int containerCount;  
};

#endif  // STORAGE_SYSTEM_H
