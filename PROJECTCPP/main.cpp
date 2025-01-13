#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include "GoodsHandler.h"
#include "StorageSystem.h"
#include "WelcomePage.h"
#include "MenuSystem.h"

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    WelcomePage welcomePage;
    welcomePage.start(); 
    MenuSystem interface;
    interface.menuSystemStart();
 
    GoodsHandler gPtr;
    gPtr.readFromFile("StoreFood.txt");
  
    return 0;
}
