#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"

GoodsHandler::GoodsHandler() : stock(new Goods* [20] {nullptr}), currentNrOfGoods(0), 
currentNrOfFood(0), currentNrOfBulk(0), foodStock(new Goods* [20] {nullptr}), bulkStock(new Goods* [20] {nullptr})
{
}

GoodsHandler::GoodsHandler(const GoodsHandler& other) : stock(new Goods* [20] {nullptr}), currentNrOfGoods(other.currentNrOfGoods), bulkStock(new Goods* [20] {nullptr}),
currentNrOfBulk(0), currentNrOfFood(0), foodStock(new Goods* [20] {nullptr})
{
	for (int i = 0; i < this->currentNrOfGoods; i++)
	{
		Bulk* bPtr = dynamic_cast<Bulk*>(other.stock[i]);

		if (bPtr != nullptr)
		{
			stock[i] = new Bulk(*bPtr);
		}
		else
		{
			Food* cPtr = dynamic_cast<Food*>(other.stock[i]);
			if (cPtr != nullptr)
			{
				stock[i] = new Food(*cPtr);
			}
		}
	}
}

//----->Destructor<-----

GoodsHandler::~GoodsHandler()
{
	// DELETING PTR STOCK
	for (int i = 0; i < this->currentNrOfGoods; i++)
	{
		std::cout << "\nDeleting contents: " << stock[i]->getName() << std::endl;
		delete this->stock[i];
	}
	delete[] stock;
	std::cout << "\nstock ptr deleted" << std::endl;
	for (int i = 0; i < this->currentNrOfBulk; i++)
	{
		delete this->bulkStock[i];
	}
	delete[] this->bulkStock;
}

//----->ADD_GOODS<-----

bool GoodsHandler::addGoods(Goods* aGoods)
{
	// Add to mixed array (stock)
	if (this->currentNrOfGoods < 20) {
		stock[this->currentNrOfGoods] = aGoods;
		this->currentNrOfGoods++;

		// Check if food or bulk and add to correct array
		Food* foodPtr = dynamic_cast<Food*>(aGoods);
		if (foodPtr != nullptr) {
			if (this->currentNrOfFood < 20) {
				foodStock[this->currentNrOfFood] = aGoods;
				this->currentNrOfFood++;
			}
		}
		else {
			Bulk* bulkPtr = dynamic_cast<Bulk*>(aGoods);
			if (bulkPtr != nullptr) {
				if (this->currentNrOfBulk < 20) {
					bulkStock[this->currentNrOfBulk] = aGoods;
					this->currentNrOfBulk++;
				}
			}
		}

		return true; // If success
	}

	return false; // If arrays are full
}

//----->SHOW_GOODS<-----

void GoodsHandler::showAll() const
{
	for (int i = 0; i < this->currentNrOfGoods; i++)
	{
		if (foodStock[i] != nullptr) {
			std::cout << this->stock[i]->toString() << std::endl;
		}
	}
}
void GoodsHandler::showFood() const
{
	std::cout << "\nShowing food items:\n";
	for (int i = 0; i < this->currentNrOfFood; i++) {
		if (foodStock[i] != nullptr) {
			std::cout << foodStock[i]->toString() << std::endl;
		}
	}
}

void GoodsHandler::showBulk() const
{
	std::cout << "\nShowing bulk items:\n";
	for (int i = 0; i < this->currentNrOfBulk; i++) {
		if (bulkStock[i] != nullptr) {
			std::cout << bulkStock[i]->toString() << std::endl;
		}
	}
}
//----->Operator<-----

void GoodsHandler::operator=(const GoodsHandler& other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			delete this->stock[i];
		}
		this->currentNrOfGoods = other.currentNrOfGoods;

		for (int i = 0; i < this->currentNrOfGoods; i++)
		{
			Bulk* bPtr = dynamic_cast<Bulk*>(other.stock[i]);

			if (bPtr != nullptr)
			{
				stock[i] = new Bulk(*bPtr);
			}
			else {
				Food* cPtr = dynamic_cast<Food*>(other.stock[i]);
				if (cPtr != nullptr)
				{
					stock[i] = new Food(*cPtr);
				}
			}
		}
	}
}
