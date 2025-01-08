#ifndef CONTAINER_H
#define CONTAINER_H

#include "Goods.h"
#include <memory>
#include <stdexcept>

#include <exception>
#include <string>

//KOLLA HUR VI SKA G�RA MED DENNA
class InvalidNameException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid name! The name cannot be empty or contain invalid characters.";
    }
};



class Container {
public:
    Container(double maxWeight);

    bool canAddGoods(double weight) const;
    void addItem(std::unique_ptr<Goods> goods);
    void showContent() const;
    bool isEmpty() const;

    double getCurrentWeight() const;
    double getMaxWeight() const;

    Goods* getItem(int index) const;

    bool isValidName(const std::string& name) const;
private:
    double maxWeight;
    double currentWeight;
    int itemCount;
    std::unique_ptr<Goods> items[100];
    bool isFirstItem;  // Flagga som h�ller koll p� om vi har lagt till en vara och vad typen �r
    bool isFoodType;   // Best�mmer om containern �r f�r Food eller Bulk
};

#endif
