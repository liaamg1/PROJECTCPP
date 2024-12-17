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
	Goods(float weight = 0.0f, const std::string& type = "Unknown",const std::string& name = "Unknown");
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

	bool operator==(const Goods & other) const;


};







#endif // !GOODS_H
