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
	char inputOptions;
	while (stop == false)
	{
		std::cout << "------>Options<------" << std::endl;
		std::cout << "Enter 1) Bulk options" << std::endl;
		std::cout << "Enter 2) Food options" << std::endl;
		std::cout << "Enter q) quit" << std::endl;
		std::cout << ">> ";
		std::cin >> input;
		std::cout<<"\n\n\n\n\n";
		if (input == '1')
		{
			while (stop == false) {
				std::cout << "------>Bulk Options<------" << std::endl;
				std::cout << "Enter 1) Add to container" << std::endl;
				std::cout << "Enter 2) Remove from container" << std::endl;
				std::cout << "Enter 2) Show current number of containers" << std::endl;
				std::cout << "Enter q) quit" << std::endl;
				std::cout << ">> ";
				std::cin >> inputOptions;
				std::cout << "\n\n";
				if (inputOptions == '1') {
					std::cout << " hej " << std::endl;
				}
				if (inputOptions == '2') {
					std::cout << " hej  hej " << std::endl;
				}
				if (inputOptions == 'q') {
					std::cout << " exiting " << std::endl;
					stop = true;
				}
			}
			stop = false;
		}
		if (input == '2')
		{
			while (stop == false) {
				std::cout << "------>Food Options<------" << std::endl;
				std::cout << "Enter 1) Add to container" << std::endl;
				std::cout << "Enter 2) Remove from container" << std::endl;
				std::cout << "Enter 2) Show current number of containers" << std::endl;
				std::cout << "Enter q) quit" << std::endl;
				std::cout << ">> ";
				std::cin >> inputOptions;
				std::cout << "\n\n";
				if (inputOptions == '1') {
					std::cout << " hej " << std::endl;
				}
				if (inputOptions == '2') {
					std::cout << " hej  hej " << std::endl;
				}
				if (inputOptions == 'q') {
					std::cout << " exiting " << std::endl;
					stop = true;
				}
			}
			stop = false;
		}
		if (input == 'q')
		{
			stop = true;
		}
	}
}
