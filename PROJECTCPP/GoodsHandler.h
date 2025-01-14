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
	int currentNrOfFood;   
	int currentNrOfBulk;   

	Goods** stock;
	Goods** foodStock;   
	Goods** bulkStock;   


public:
	GoodsHandler(int capacity = 10);
	~GoodsHandler();
	void showTotals() const;
	double calculateTotal(double (*calcFunc)(const Goods*)) const;
	bool addGoods(Goods* aGoods);

	void showAll(char sortChoice);
	void showFood() const;            
	void showBulk() const;           

	bool isValidName(const std::string& name) const;
	void readFromFile(const std::string& filename);
	void addToFile();
	void cleanseFileFromCurrentContents(const std::string& filename);

	int getCurrentNrOfGoods();
	Goods* getCurrentIndex(int index);

	void expandStock();
	
};
#endif // !GOODS_HANDLER_H
