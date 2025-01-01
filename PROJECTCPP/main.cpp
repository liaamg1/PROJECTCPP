#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include "GoodsHandler.h"
#include "StorageSystem.h"
int main() {
    // Skapa ett StorageSystem
    StorageSystem storage;

    // TEMPORARY ADD CONTAINERS
    storage.addContainer(100.0);  // Container 1, maxvikt 100
    storage.addContainer(150.0);  // Container 2, maxvikt 150
    storage.addContainer(200.0);  // Container 3, maxvikt 200

    // Skapa några varor
    Goods* apple = new Food(10, 5.0f, "Apple");   // 10 stycken äpplen, vikt 5.0 kg
    Goods* banana = new Food(20, 7.0f, "Banana"); // 20 stycken bananer, vikt 7.0 kg
    Goods* rice = new Bulk(50.0f, 25.0f, "Rice");  // 50 liter ris, vikt 25.0 kg
    Goods* wheat = new Bulk(60.0f, 40.0f, "Wheat"); // 60 liter vete, vikt 40.0 kg

   
    storage.addGoodsToContainer(apple);
    storage.addGoodsToContainer(banana); 

   
    storage.addGoodsToContainer(rice); 
    storage.addGoodsToContainer(wheat);


    storage.addGoodsToContainer(rice);  
    storage.addGoodsToContainer(apple); 

    // Visa innehåll i alla containrar
    storage.showAllContainers();

    // Rensa upp
    delete apple;
    delete banana;
    delete rice;
    delete wheat;

    return 0;
}
