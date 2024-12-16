#include "StorageSystem.h"

StorageSystem::StorageSystem(int capacity) : currentNrOfContainers(0), capacity(capacity), containers(new Container* [20] {nullptr})
{
}

StorageSystem::~StorageSystem()
{
	for (int i = 0; i < currentNrOfContainers; i++)
	{
		delete containers[i];
	}
	delete containers;
}

//----->ADD_CONTAINERS<-----

void StorageSystem::addContainer(int amount, int weight, const std::string& type, const std::string& name)
{
	if (this->currentNrOfContainers == this->capacity) {
		this->expand();
	}
	this->containers[this->currentNrOfContainers] = new Container(amount, weight, type, name);
	this->currentNrOfContainers++;
}

//----->REMOVE_CONTAINERS<-----

bool StorageSystem::removeContainers(int amount, int weight, const std::string& type, const std::string& name)
{
	bool didRemove;
	for (int i = 0; i < this->currentNrOfContainers; i++)
	{
		if (*this->containers[i] == new Container(amount, weight, type, name)
		{

		}
	}
	return didRemove;
}

//----->EXPAND_CONTAINERS<-----

void StorageSystem::expand()
{
	this->capacity += 5;
	Container** temp = new Container * [this->capacity] {nullptr};

	for (int i = 0; i < this->currentNrOfContainers; i++)
	{
		temp[i] = this->containers[i];
	}
	delete[] this->containers;
	this->containers = temp;
}

