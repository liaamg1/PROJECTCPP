#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <string>

class Goods
{
private:
	float weight;
	std::string name;
	std::string type;

public:
	Goods(float weight = 0.0f, const std::string& name = "Unknown");
	virtual ~Goods();

	//GET
	std::string getName() const;
	float getWeight() const;
	//virtual float getVolume() const { return 0.0f; }  // Standardvärde för varor som inte har volym
	//virtual int getQuantity() const { return 0; }
	//SET
	void setWeight(float weight);
	void setName(std::string name);

	virtual std::string toString() const;
};







#endif // !GOODS_H
