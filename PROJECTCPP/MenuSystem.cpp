#include "MenuSystem.h"

MenuSystem::MenuSystem() {
    storageSystem = std::make_unique<StorageSystem>();  // Använd std::make_unique för att skapa ett StorageSystem
}

MenuSystem::~MenuSystem() {
    // Vi behöver inte längre radera storageSystem manuellt eftersom det hanteras av unique_ptr
}

void MenuSystem::menuSystemStart() {
    bool stop = false;
    char input;
    char inputOptions;

    while (!stop) {
        std::cout << "------> Main Menu <------" << std::endl;
        std::cout << "Enter 1) Bulk options" << std::endl;
        std::cout << "Enter 2) Food options" << std::endl;
        std::cout << "Enter 3) Show all containers" << std::endl;
        std::cout << "Enter 4) Show totals (weight, volume, quantity)" << std::endl;
        std::cout << "Enter 5) Show all Goods" << std::endl;
        std::cout << "Enter 6) Save current objects to database" << std::endl;
        std::cout << "Enter 7) Remove current objects in files" << std::endl;

        std::cout << "Enter q) Quit" << std::endl;
        std::cout << ">> ";
        std::cin >> input;
        std::cout << "\n\n\n";

        if (input == '1') {
            // Bulk options
            while (!stop) {
                std::cout << "------> Bulk Options <------" << std::endl;
                std::cout << "Enter 1) Add Bulk to container" << std::endl;
                std::cout << "Enter 2) Show all Bulk items" << std::endl;
                std::cout << "Enter q) Back to main menu" << std::endl;
                std::cout << ">> ";
                std::cin >> inputOptions;
                std::cout << "\n\n";

                if (inputOptions == '1') {
                    addBulkToContainer();
                }
                else if (inputOptions == '2') {
                    goodsHandler.showBulk();
                }
                else if (inputOptions == 'q') {
                    stop = true;
                    break;
                }
            }
            stop = false;
        }
        else if (input == '2') {
            // Food options
            while (!stop) {
                std::cout << "------> Food Options <------" << std::endl;
                std::cout << "Enter 1) Add Food to container" << std::endl;
                std::cout << "Enter 2) Show all Food items" << std::endl;
                std::cout << "Enter q) Back to main menu" << std::endl;
                std::cout << ">> ";
                std::cin >> inputOptions;
                std::cout << "\n\n";

                if (inputOptions == '1') {
                    addFoodToContainer();
                }
                else if (inputOptions == '2') {
                    goodsHandler.showFood();
                }
                else if (inputOptions == 'q') {
                    stop = true;
                    break;
                }
            }
            stop = false;
        }
        else if (input == '3') {
            storageSystem->showAllContainers();
        }
        else if (input == '4') {
            goodsHandler.showTotals();
        }
        else if (input == '5') {
            // Show all Goods
            goodsHandler.showAll();
        }
        else if (input == '6') {
            goodsHandler.addToFile();
        }
        else if (input == '7') {
            goodsHandler.cleanseFileFromCurrentContents("StoredFood.txt");
            goodsHandler.cleanseFileFromCurrentContents("StoredBulk.txt");
        } 
        else if (input == 'q') {
            stop = true;
        }
    }
}

void MenuSystem::addBulkToContainer() {
    // För att lägga till en Bulk till en container direkt
    std::string name;
    float weight, volume;

    std::cout << "Enter Food name:" << std::endl;
    std::cout << ">> ";
    std::cin >> name;
    std::cout << "\nEnter Food weight:" << std::endl;
    std::cout << ">> ";
    std::cin >> weight;
    std::cout << "\nEnter Food quantity:" << std::endl;
    std::cout << ">> ";
    std::cin >> volume;

    // Skapa ett Bulk objekt med std::make_unique
    auto bulkItem = std::make_unique<Bulk>(volume, weight, name);
    goodsHandler.addGoods(bulkItem.get());  // Lägg till varan i GoodsHandler (använd get() för att få en rå pekare)

    // Lägg direkt till Bulk i en container genom att flytta ägandeskapet
    if (storageSystem->addGoods(std::move(bulkItem))) {
        std::cout << "\nBulk item added to container." << std::endl;
    }
    else {
        std::cout << "\nFailed to add Bulk item to container." << std::endl;
    }
}

void MenuSystem::addFoodToContainer() {
    // För att lägga till en Food till en container direkt
    std::string name;
    float weight;
    int quantity;

    std::cout << "Enter Food name:" << std::endl;
    std::cout << ">> ";
    std::cin >> name;
    std::cout << "\nEnter Food weight:" << std::endl;
    std::cout << ">> ";
    std::cin >> weight;
    std::cout << "\nEnter Food quantity:" << std::endl;
    std::cout << ">> ";
    std::cin >> quantity;

    // Skapa ett Food objekt med std::make_unique
    auto foodItem = std::make_unique<Food>(quantity, weight, name);
    goodsHandler.addGoods(foodItem.get());
    // Lägg direkt till Food i en container genom att flytta ägandeskapet
    if (storageSystem->addGoods(std::move(foodItem))) {
        std::cout << "\nFood item added to container." << std::endl;
    }
    else {
        std::cout << "\nFailed to add Food item to container." << std::endl;
    }
}
