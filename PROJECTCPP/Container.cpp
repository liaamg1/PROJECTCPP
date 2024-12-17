#include "Container.h"
#include <string>

Container::Container(float maxWeight, const std::string& containerType) : maxWeight(maxWeight), usedWeight(0), containerType(containerType), foodCount(0)
{
	for (int i = 0; i < MAX_GOODS; ++i) {
		foodGoods[i] = nullptr;  // Sätt varje element i foodGoods till nullptr
	}
}

float Container::getMaxWeight() const
{
	return maxWeight;
}

float Container::getUsedWeight() const
{
	return usedWeight;
}

std::string Container::getContainerType() const
{
	return containerType;
}

bool Container::storeFood(Goods* food)
{
	if (foodCount < MAX_GOODS && food != nullptr && food->getType()=="Food")
	{
		if (usedWeight + food->getWeight() <= maxWeight) {
			foodGoods[foodCount++] = food;  // Lägg till varan i food-arrayen
			usedWeight += food->getWeight();
			std::cout << food->getName() << " added to the container." << std::endl;
			return true;
		}
		else
		{
			std::cout << "Too heavy! Can not add " <<food->getName()<< " "<<food->getWeight()<<" kg" << std::endl;
			std::cout << "You can add " << (maxWeight - usedWeight) << " kg" << std::endl;
			std::cout<<std::endl;
		}
	}
	return false;
}

void Container::displayInfo() const
{
	std::cout << "Container Type: " << containerType << std::endl;
	std::cout << "Max Weight: " << maxWeight << " kg\n";
	std::cout << "Used Weight: " << usedWeight << " kg\n";
	std::cout << "Items in the container:\n";

	for (int i = 0; i < foodCount; ++i) {
		std::cout << "- " << foodGoods[i]->getName() << " (Weight: " << foodGoods[i]->getWeight() << " kg)\n";
	}
}
