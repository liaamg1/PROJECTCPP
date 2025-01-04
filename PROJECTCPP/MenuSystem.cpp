#include "MenuSystem.h"

MenuSystem::MenuSystem()
{
}

MenuSystem::~MenuSystem()
{
}

void MenuSystem::menuSystemStart()
{
	bool stop = false;
	char input;
	while (stop == false)
	{
		std::cout << "Enter 1) Bulk options" << std::endl;
		std::cout << "Enter 2) Food options" << std::endl;
		std::cout << "Enter q) quit" << std::endl;
		std::cout << ">> ";
		std::cin >> input;
		std::cout<<std::endl;
		if (input == 'q')
		{
			stop = true;
		}
	}
}
