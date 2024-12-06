#include <iostream>
#include <string>
#include "Goods.h"
int main() {
	std::cout << "Hello World!" << std::endl; // TEST 1
	Goods goods1(500, 2, "Koppar", "EU");
	std::cout << goods1.getType() << std::endl;
	return 0;
}