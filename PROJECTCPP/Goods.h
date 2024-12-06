#ifndef GOODS_H
#define GOODS_H
#include <iostream>
#include <string>

class Goods
{
public:
	Goods();
	Goods(int weight, int amount, const std::string& type, const std::string& pallet);
	~Goods();

	//GET
	int getWeight();
	int getAmount();
	std::string getType() const;
	std::string getPallet() const;

	//SET
	void setWeight(int weight);
	void setAmount(int amount);
	void setType(const std::string& type);
	void setPallet(const std::string& pallet);


private:
	int weight;
	int amount;
	std::string type;
	std::string pallet;
};
#endif // !GOODS_H

