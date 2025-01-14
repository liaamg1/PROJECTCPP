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
        std::cout << "Enter 5) Sorting Options" << std::endl;
        std::cout << "Enter 6) File Options" << std::endl;
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
            while (!stop) {
                std::cout << "------> Sorting Options <------" << std::endl;
                std::cout << "Enter 1) Sort by weight" << std::endl;
                std::cout << "Enter 2) Sort by name" << std::endl;
                std::cout << "Enter q) Back to main menu" << std::endl;
                std::cout << ">> ";
                std::cin >> inputOptions;
                std::cout << "\n\n\n";
                if (inputOptions == '1' || inputOptions == '2')
                {
                    goodsHandler.showAll(inputOptions);
                }
                else if (inputOptions == 'q') {
                    stop = true;
                }
            }
            stop = false;
        }
        else if (input == '6'){
            while (!stop) {
                std::cout << "------> File Options <------" << std::endl;
                std::cout << "Enter 1) Save current objects to Files" << std::endl;
                std::cout << "Enter 2) Cleanse Files from their current Holdings" << std::endl;
                std::cout << "Enter q) Back to main menu" << std::endl;
                std::cout << ">> ";
                std::cin >> inputOptions;
                std::cout << "\n\n\n";
                if (inputOptions == '1') {
                    goodsHandler.addToFile();
                    std::cout << "Objects added: " << goodsHandler.getCurrentNrOfGoods() << "\n" << std::endl;
                }
                else if (inputOptions == '2') {
                    goodsHandler.cleanseFileFromCurrentContents("StoredFood.txt");
                    goodsHandler.cleanseFileFromCurrentContents("StoredBulk.txt");
                    std::cout << "Objects Removed: " << goodsHandler.getCurrentNrOfGoods() << "\n" << std::endl;
                }
                else if (inputOptions == 'q') {
                    stop = true;
                }
            }
            stop = false;
        }
        else if (input == 'q') {
            stop = true;
        }
    }
}

void MenuSystem::addBulkToContainer() {
    try {
        std::string name, weightStr, volumeStr;

        std::cout << "Enter Bulk name:" << std::endl;
        std::cout << ">> ";
        std::cin >> name;

        if (name.empty() || !InvalidNameException::isValidName(name)) {
            throw InvalidNameException();
        }

        std::cout << "\nEnter Bulk weight (must be a positive number):" << std::endl;
        std::cout << ">> ";
        std::cin >> weightStr;

        if (!InvalidNameException::isValidNumber(weightStr)) {
            throw  InvalidNameException();;
        }
        float weight = std::stof(weightStr);

        std::cout << "\nEnter Bulk volume (must be a positive number):" << std::endl;
        std::cout << ">> ";
        std::cin >> volumeStr;

        if (!InvalidNameException::isValidNumber(volumeStr)) {
            throw  InvalidNameException();;
        }
        float volume = std::stof(volumeStr);

        auto bulkItem = std::make_unique<Bulk>(volume, weight, name);
        goodsHandler.addGoods(bulkItem.get());

        if (storageSystem->addGoods(std::move(bulkItem))) {
            std::cout << "\nBulk item added to container.\n" << std::endl;
        }
        else {
            std::cout << "\nFailed to add Bulk item to container.\n" << std::endl;
        }
    }
    catch (const InvalidNameException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "General error: " << e.what() << std::endl;
    }
}


void MenuSystem::addFoodToContainer() {
    try {
        std::string name, weightStr, quantityStr;

        std::cout << "Enter Food name:" << std::endl;
        std::cout << ">> ";
        std::cin >> name;

        if (name.empty() || !InvalidNameException::isValidName(name)) {
            throw InvalidNameException();
        }

        std::cout << "\nEnter Food weight per quantity (must be a positive number):" << std::endl;
        std::cout << ">> ";
        std::cin >> weightStr;

        if (!InvalidNameException::isValidNumber(weightStr)) {
            throw InvalidNameException();
        }
        float weight = std::stof(weightStr);

        std::cout << "\nEnter Food quantity (must be a positive number):" << std::endl;
        std::cout << ">> ";
        std::cin >> quantityStr;

        if (!InvalidNameException::isValidNumber(quantityStr)) {
            throw InvalidNameException();
        }
        int quantity = std::stoi(quantityStr);

        float sumOfWeightAndQuantity = quantity * weight;
        auto foodItem = std::make_unique<Food>(quantity, sumOfWeightAndQuantity, name);
        goodsHandler.addGoods(foodItem.get());

        if (storageSystem->addGoods(std::move(foodItem))) {
            std::cout << "\nFood item added to container.\n" << std::endl;
        }
        else {
            std::cout << "\nFailed to add Food item to container.\n" << std::endl;
        }
    }
    catch (const InvalidNameException& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "General error: " << e.what() << std::endl;
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

