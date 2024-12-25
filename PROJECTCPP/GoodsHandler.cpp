#include "GoodsHandler.h"
#include "Bulk.h"
#include "Food.h"

GoodsHandler::GoodsHandler() : stock(new Goods* [20] {nullptr}), currentNrOfGoods(0)
{
}

GoodsHandler::GoodsHandler(const GoodsHandler& other) : stock(new Goods* [20] {nullptr}), currentNrOfGoods(other.currentNrOfGoods)
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
	delete this->stock;
	std::cout << "\nstock ptr deleted" << std::endl;
}

//----->ADD_GOODS<-----

bool GoodsHandler::addGoods(Goods* aGoods)
{
	bool didAdd = false;
	if (this->currentNrOfGoods<20){
		this->stock[this->currentNrOfGoods] = aGoods;
		this->currentNrOfGoods++;
		didAdd = true;
	}
	return didAdd;
}

//----->SHOW_GOODS<-----

void GoodsHandler::showAll() const
{
	for (int i = 0; i < this->currentNrOfGoods; i++)
	{
		std::cout << this->stock[i]->toString() << std::endl;
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
