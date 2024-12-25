#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H
#include "Goods.h"

class GoodsHandler
{
private:
	int currentNrOfGoods;
	Goods** stock;

public:
	GoodsHandler();
	GoodsHandler(const GoodsHandler& other);
	~GoodsHandler();

	bool addGoods(Goods* aGoods);
	void showAll() const;
	void operator=(const GoodsHandler& other);

};
#endif // !GOODS_HANDLER_H
