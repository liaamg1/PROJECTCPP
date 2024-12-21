#include "GoodsHandler.h"

GoodsHandler::GoodsHandler() : Food(new Goods* [capFood] {nullptr}), Bulk(new Goods* [capBulk] { nullptr }), currentNrOfGoods(0)
{
}

GoodsHandler::GoodsHandler(const GoodsHandler& other) : Food(new Goods* [capFood] {nullptr}), Bulk(new Goods* [capBulk] { nullptr }), currentNrOfGoods(other.currentNrOfGoods)
{
}

//----->Destructor<-----

GoodsHandler::~GoodsHandler()
{
	// DELETING PTR BULK
	for (int i = 0; i < capBulk; i++)
	{
		delete this->Bulk[i];
	}
	delete Bulk;
	// DELETING PTR FOOD
	for (int i = 0; i < capFood; i++)
	{
		delete this->Food[i];
	}
	delete Food;
}
