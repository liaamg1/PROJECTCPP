#ifndef MENUSYSTEM_H
#define MENUSYSTEM_H

#include "StorageSystem.h"
#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"
#include <memory>  // F�r att anv�nda std::unique_ptr

class MenuSystem {
public:
    // Konstruktor och destruktor
    MenuSystem();
    ~MenuSystem();

    // Funktion som startar huvudmenyn
    void menuSystemStart();

private:
    // Hj�lpfunktioner f�r att hantera varor
    void addBulkToContainer();
    void addFoodToContainer();
    void loadGoodsFromFile();
    // Pekare till StorageSystem och GoodsHandler
    std::unique_ptr<StorageSystem> storageSystem;  // Anv�nd unique_ptr f�r att hantera StorageSystem
    GoodsHandler goodsHandler;  // Antas vara en instans av GoodsHandler, kan justeras om det beh�vs
};

#endif // MENUSYSTEM_H
