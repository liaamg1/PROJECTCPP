#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>

class Goods
{
private:
	float weight;
	int quantity;
	std::string name;
	std::string type;

public:
	Goods();
	~Goods();

	//GET
	void getName() const;
	void getWeight() const;
	void getQuantity() const;


};







#endif // !GOODS_H
