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
    // Skapa ett objekt och starta animationen
    //WelcomePage welcomePage;
    //welcomePage.start();  // Kallar på den enda funktionen som startar allt
   /* MenuSystem interface;
    interface.menuSystemStart();*/
 
    GoodsHandler gPtr;
    gPtr.readFromFile("StoredFood.txt");
  
    return 0;
}
