#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H

#include "Food.h"
#include "Bulk.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Sorter.h"


class GoodsHandler
{
private:
	int capacity;
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
	void showTotals() const;
	double calculateTotal(double (*calcFunc)(const Goods*)) const;
	bool addGoods(Goods* aGoods);
	     // L�gga till i Bulk-arrayen
	void showAll(int sortChoice);
	void showFood() const;             // Visa endast Food-objekt
	void showBulk() const;             // Visa endast Bulk-objekt
	void operator=(const GoodsHandler& other);
	bool isValidName(const std::string& name) const;
	void readFromFile(const std::string& filename);
	void addToFile();
	void cleanseFileFromCurrentContents(const std::string& filename);
	int getCurrentNrOfGoods();
	Goods* getCurrentIndex(int index);
	void expandStock();
	void expandFoodStock();
	void expandBulkStock();
};
#endif // !GOODS_HANDLER_H
