#ifndef GOODS_HANDLER_H
#define GOODS_HANDLER_H
#include "Goods.h"
#include <vector>
#include <fstream>

class GoodsHandler
{
private:
	int currentNrOfGoods;
	int currentNrOfFood;   // Antal Food-objekt
	int currentNrOfBulk;   // Antal Bulk-objekt

	std::vector<Goods**> entryAndExitStock;
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
	void readFromFile(std::vector<Goods**> entryAndExitStock, const std::string& filename);
};
#endif // !GOODS_HANDLER_H
