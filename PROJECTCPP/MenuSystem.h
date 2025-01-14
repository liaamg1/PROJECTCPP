#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "StorageSystem.h"
#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"
#include <memory>  

class MenuSystem {
public:
    MenuSystem();
    ~MenuSystem();

    void menuSystemStart();

private:
    void addBulkToContainer();
    void addFoodToContainer();
    void loadGoodsFromFile();

    std::unique_ptr<StorageSystem> storageSystem;  
    GoodsHandler goodsHandler;  
};

#endif // MENUSYSTEM_H
