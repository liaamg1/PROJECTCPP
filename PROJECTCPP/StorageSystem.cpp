#include "StorageSystem.h"
#include <fstream>

StorageSystem::StorageSystem(int capacity) : currentNrOfContainers(0), capacity(capacity), containers(new Container* [20] {nullptr})
{
}

//----->DESTRUCTOR<-----

StorageSystem::~StorageSystem()
{
	for (int i = 0; i < this->currentNrOfContainers; i++)
	{
		delete this->containers[i];
	}
	delete this->containers;
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

bool StorageSystem::removeContainer(int amount, int weight, const std::string& type, const std::string& name)
{
	bool didRemove = false;
	for (int i = 0; i < this->currentNrOfContainers && !didRemove; i++)
	{
		if (*this->containers[i] == new Container(amount, weight, type, name)
			{
				delete this->containers[i];
				this->currentNrOfContainers--;
				this->containers[i] = this->containers[currentNrOfContainers];
				this->containers[this->currentNrOfContainers] = nullptr;
				didRemove = true;
			}
	}
	return didRemove;
}

//----->DISPLAY_CONTAINERS<-----

void StorageSystem::displayAllContainers()
{
	for (int i = 0; i < this->currentNrOfContainers; i++)
	{
		std::cout << this->containers[i]->toString() << std::endl;
	}
}

//----->SAVE_CONTAINERS_TO_FILE<-----

void StorageSystem::saveToFile()
{
	std::ofstream outStream("container_data.txt");
	if (!outStream){
		std::cerr << "Error creating file" << std::endl;
	}
	else {
		for (int i = 0; i < this->currentNrOfContainers; i++)
		{
			this->containers[i]->getAmount() >> outStream;
			this->containers[i]->getWeight() >> outStream;
			this->containers[i]->getType() >> outStream;
			this->containers[i]->getName() >> outStream;
		}
		outStream.close();
	}
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

