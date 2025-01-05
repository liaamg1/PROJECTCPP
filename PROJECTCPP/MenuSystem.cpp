#include "MenuSystem.h"
#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"
#include <iostream>
#include <memory>  // För att använda std::unique_ptr

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
            // Show all containers
            storageSystem->showAllContainers();
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

    std::cout << "Enter Bulk name: ";
    std::cin >> name;
    std::cout << "Enter Bulk weight: ";
    std::cin >> weight;
    std::cout << "Enter Bulk volume: ";
    std::cin >> volume;

    // Skapa ett Bulk objekt med std::make_unique
    auto bulkItem = std::make_unique<Bulk>(volume, weight, name);
    goodsHandler.addGoods(bulkItem.get());  // Lägg till varan i GoodsHandler (använd get() för att få en rå pekare)

    // Lägg direkt till Bulk i en container genom att flytta ägandeskapet
    if (storageSystem->addGoods(std::move(bulkItem))) {
        std::cout << "Bulk item added to container." << std::endl;
    }
    else {
        std::cout << "Failed to add Bulk item to container." << std::endl;
    }
}

void MenuSystem::addFoodToContainer() {
    // För att lägga till en Food till en container direkt
    std::string name;
    float weight;
    int quantity;

    std::cout << "Enter Food name: ";
    std::cin >> name;
    std::cout << "Enter Food weight: ";
    std::cin >> weight;
    std::cout << "Enter Food quantity: ";
    std::cin >> quantity;

    // Skapa ett Food objekt med std::make_unique
    auto foodItem = std::make_unique<Food>(weight, quantity, name);

    // Lägg direkt till Food i en container genom att flytta ägandeskapet
    if (storageSystem->addGoods(std::move(foodItem))) {
        std::cout << "Food item added to container." << std::endl;
    }
    else {
        std::cout << "Failed to add Food item to container." << std::endl;
    }
}
