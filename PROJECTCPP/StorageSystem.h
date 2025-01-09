#ifndef STORAGE_SYSTEM_H
#define STORAGE_SYSTEM_H

#include "Container.h"


class StorageSystem {
public:
    // Konstruktor och Destruktor
    StorageSystem();
    ~StorageSystem();

    // Lägg till en ny container
    bool addContainer(double maxWeight);

    // Lägg till varor i containrar
    bool addGoods(std::unique_ptr<Goods> goods);

    // Visa alla containrar och deras innehåll
    void showAllContainers() const;

private:
    static const int MAX_CONTAINERS = 10;  // Max antal containrar
    std::unique_ptr<Container> containers[MAX_CONTAINERS];  // En array av unika containrar
    int containerCount;  // Håller reda på antalet containrar
};

#endif  // STORAGE_SYSTEM_H
