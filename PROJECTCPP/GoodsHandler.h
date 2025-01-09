#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H

#include "Food.h"
#include "Bulk.h"
#include <vector>
#include <fstream>
#include <algorithm>

class GoodsHandler
{
private:
	int currentNrOfGoods;
	int currentNrOfFood;   // Antal Food-objekt
	int currentNrOfBulk;   // Antal Bulk-objekt

	Goods** stock;
	Goods** foodStock;   // Array för Food-objekt
	Goods** bulkStock;   // Array för Bulk-objekt


public:
	GoodsHandler();
	GoodsHandler(const GoodsHandler& other);
	~GoodsHandler();
	void showTotals() const;
	double calculateTotal(double (*calcFunc)(const Goods*)) const;
	bool addGoods(Goods* aGoods);
	     // Lägga till i Bulk-arrayen
	void showAll() const;
	void showFood() const;             // Visa endast Food-objekt
	void showBulk() const;             // Visa endast Bulk-objekt
	void operator=(const GoodsHandler& other);
	bool isValidName(const std::string& name) const;
	void readFromFile(const std::string& filename);
	void addToFile();
};
#endif // !GOODS_HANDLER_H
