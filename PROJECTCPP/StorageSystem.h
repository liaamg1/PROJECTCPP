#ifndef STORAGE_SYSTEM_H
#define STORAGE_SYSTEM_H

#include "Container.h"
#include "Goods.h"
#include <iostream>

class StorageSystem {
private:
    Container* containers[10];
    int containerCount;

public:
    StorageSystem();
    ~StorageSystem();

    bool addContainer(double maxWeight);
    bool addGoodsToContainer(Goods* goods);
    void showAllContainers() const;
};

#endif
