#include <iostream>
#include "Container.h"
#include "Food.h"
#include "Bulk.h"
#include "GoodsHandler.h"
#include "StorageSystem.h"
#include "WelcomePage.h"

int main() {
    // Skapa ett objekt och starta animationen
    WelcomePage welcomePage;
    welcomePage.start();  // Kallar p� den enda funktionen som startar allt

    return 0;
}
