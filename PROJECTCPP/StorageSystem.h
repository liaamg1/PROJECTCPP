#pragma once
#include "Container.h"
#include "Goods.h"

class StorageSystem {
private:
    Container* containers[10];  // Förvara upp till 10 containrar
    int containerCount;

public:
    StorageSystem();
    ~StorageSystem();

    bool addContainer(double maxWeight);  // Skapa en ny container
    void showAllContainers() const;      // Visa alla containrar
    bool addGoods(Goods* goods);         // Lägg till varor i containrar
};
