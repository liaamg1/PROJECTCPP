#ifndef STORAGE_SYSTEM_H
#define STORAGE_SYSTEM_H
#include "Container.h"
#include <iostream>

class StorageSystem
{
private:
	container** containers;
	int currentNrOfContainers;
	int capacity;
	void expand();
public:
	StorageSystem(int capacity = 3);
	~StorageSystem();
	
	void addContainer(int amount, int weight, const std::string& type, const std::string& name);
	bool removeContainers(int amount, int weight, const std::string& type, const std::string& name);
	void displarAllContainers();
	bool saveToFile();

};
#endif // !STORAGE_SYSTEM_H
