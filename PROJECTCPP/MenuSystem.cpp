#include "MenuSystem.h"

MenuSystem::MenuSystem() {
    storageSystem = std::make_unique<StorageSystem>();  
}

MenuSystem::~MenuSystem() {
}

void MenuSystem::menuSystemStart() {
    bool stop = false;
    char input;
    char inputOptions;
    loadGoodsFromFile();
   
    while (!stop) {
        std::cout << "------> Main Menu <------" << std::endl;
        std::cout << "Enter 1) Bulk options" << std::endl;
        std::cout << "Enter 2) Food options" << std::endl;
        std::cout << "Enter 3) Show all containers" << std::endl;
        std::cout << "Enter 4) Show totals (weight, volume, quantity)" << std::endl;
        std::cout << "Enter 5) Show all Goods" << std::endl;
        std::cout << "Enter 6) Save current objects to files" << std::endl;
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
                std::cout << "\n\n\n";

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
                std::cout << "\n\n\n";

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
           
            std::cout << "1. Sort by weight" << std::endl;
            std::cout << "2. Sort by name" << std::endl;
            int sortType;
            std::cout << ">> ";
            std::cin >> sortType;
            std::cout << std::endl;
            goodsHandler.showAll(sortType);
        }
        else if (input == '6') {
            goodsHandler.addToFile();
            std::cout << "Objects added: " << goodsHandler.getCurrentNrOfGoods() << "\n" << std::endl;
        }
        else if (input == '7') {
            goodsHandler.cleanseFileFromCurrentContents("StoredFood.txt");
            goodsHandler.cleanseFileFromCurrentContents("StoredBulk.txt");
            std::cout << "Objects Removed: " << goodsHandler.getCurrentNrOfGoods() << "\n" << std::endl;
        } 
       
        else if (input == 'q') {
            stop = true;
        }
    }
}

void MenuSystem::addBulkToContainer() {
   
    std::string name;
    float weight, volume;

    std::cout << "Enter Bulk name:" << std::endl;
    std::cout << ">> ";
    std::cin >> name;
    std::cout << "\nEnter Bulk weight:" << std::endl;
    std::cout << ">> ";
    std::cin >> weight;
    std::cout << "\nEnter Bulk volume:" << std::endl;
    std::cout << ">> ";
    std::cin >> volume;
    std::cout << "\n" << std::endl;

   
    auto bulkItem = std::make_unique<Bulk>(volume, weight, name);
    goodsHandler.addGoods(bulkItem.get());  

    
    if (storageSystem->addGoods(std::move(bulkItem))) {
        std::cout << "\nBulk item added to container.\n" << std::endl;
    }
    else {
        std::cout << "\nFailed to add Bulk item to container.\n" << std::endl;
    }
}

void MenuSystem::addFoodToContainer() {
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
    std::cout << "\n" << std::endl;

    auto foodItem = std::make_unique<Food>(quantity, weight, name);
    goodsHandler.addGoods(foodItem.get());

    if (storageSystem->addGoods(std::move(foodItem))) {
        std::cout << "\nFood item added to container.\n" << std::endl;
    }
    else {
        std::cout << "\nFailed to add Food item to container.\n" << std::endl;
    }
}

void MenuSystem::loadGoodsFromFile() {
    std::cout << "Loading objects from files and adding to containers...\n" << std::endl;

    //LOAD OBJECTS
    goodsHandler.readFromFile("StoredFood.txt");
    goodsHandler.readFromFile("StoredBulk.txt");
    
    for (int i = 0; i < goodsHandler.getCurrentNrOfGoods(); i++) {
        Goods* item = goodsHandler.getCurrentIndex(i);
        if (item != nullptr) {
            std::unique_ptr<Goods> itemPtr(item); 

            if (!storageSystem->addGoods(std::move(itemPtr))) {
                std::cout << "Failed to add object to container: " << item->getName() << std::endl;
            }
            else {
                std::cout << "Object added to container: " << item->getName() << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

