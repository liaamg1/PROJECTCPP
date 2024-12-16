#include "Container.h"


Container::Container(float maxWeight, const std::string& containerType) : maxWeight(maxWeight), usedWeight(0), containerType(containerType)
{
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
