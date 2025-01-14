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

	std::string getName() const;
	float getWeight() const;

	void setWeight(float weight);
	void setName(std::string name);

	virtual std::string toString() const = 0;
};
#endif // !GOODS_H
