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
	void setWeight(float weight);
	void setName(std::string name);
	void setType(std::string type);



};







#endif // !GOODS_H
