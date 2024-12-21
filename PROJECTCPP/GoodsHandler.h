#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H
#include "Goods.h"
int capBulk; // Dynamic roof
int capFood; // Dynamic roof

class GoodsHandler
{
private:
	int currentNrOfGoods;
	Goods** Food;
	Goods** Bulk;

public:
	GoodsHandler();
	GoodsHandler(const GoodsHandler& other);
	~GoodsHandler();

};
#endif // !GOODS_HANDLER_H
