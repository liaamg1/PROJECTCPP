#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "StorageSystem.h"
#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"
#include <memory>  // För att använda std::unique_ptr

class MenuSystem {
public:
    // Konstruktor och destruktor
    MenuSystem();
    ~MenuSystem();

    // Funktion som startar huvudmenyn
    void menuSystemStart();

private:
    // Hjälpfunktioner för att hantera varor
    void addBulkToContainer();
    void addFoodToContainer();
    void loadGoodsFromFile();
    // Pekare till StorageSystem och GoodsHandler
    std::unique_ptr<StorageSystem> storageSystem;  // Använd unique_ptr för att hantera StorageSystem
    GoodsHandler goodsHandler;  // Antas vara en instans av GoodsHandler, kan justeras om det behövs
};

#endif // MENUSYSTEM_H
