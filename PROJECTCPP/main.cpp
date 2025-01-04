#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include "GoodsHandler.h"
#include "StorageSystem.h"
#include "WelcomePage.h"
#include "MenuSystem.h"

int main() {
    // Skapa ett objekt och starta animationen
    WelcomePage welcomePage;
    welcomePage.start();  // Kallar på den enda funktionen som startar allt
    MenuSystem interface;
    interface.menuSystemStart();
    return 0;
}
