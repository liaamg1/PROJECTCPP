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
	Goods();
	~Goods();

	//GET
	std::string getName() const;
	float getWeight() const;
	std::string getType() const;
	virtual float getVolume() const { return 0.0f; }  // Standardvärde för varor som inte har volym
	virtual int getQuantity() const { return 0; }
	//SET
	void setWeight(float weight);
	void setName(std::string name);
	void setType(std::string type);




};







#endif // !GOODS_H
