// MenuSystem.h

#pragma once
#include "StorageSystem.h"
#include "GoodsHandler.h"

class MenuSystem {
public:
    MenuSystem();
    ~MenuSystem();

    void menuSystemStart();
    void addBulkToContainer();
    void addFoodToContainer();

private:
    StorageSystem* storageSystem;  // Pekare till StorageSystem
    GoodsHandler goodsHandler;  // Här gör vi GoodsHandler till en långlivad instans
};
