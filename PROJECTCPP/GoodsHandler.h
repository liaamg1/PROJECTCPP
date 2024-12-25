#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H
#include "Goods.h"

class GoodsHandler
{
private:
	int currentNrOfGoods;
	int currentNrOfFood;   // Antal Food-objekt
	int currentNrOfBulk;   // Antal Bulk-objekt
	Goods** stock;
	Goods** foodStock;   // Array f�r Food-objekt
	Goods** bulkStock;   // Array f�r Bulk-objekt


public:
	GoodsHandler();
	GoodsHandler(const GoodsHandler& other);
	~GoodsHandler();

	bool addGoods(Goods* aGoods);
	     // L�gga till i Bulk-arrayen
	void showAll() const;
	void showFood() const;             // Visa endast Food-objekt
	void showBulk() const;             // Visa endast Bulk-objekt
	void operator=(const GoodsHandler& other);

};
#endif // !GOODS_HANDLER_H
