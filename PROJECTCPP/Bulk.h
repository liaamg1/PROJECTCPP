#ifndef BULK_H
#define BULK_H
#include "Goods.h"

class Bulk : public Goods
{
private:
	float volume;

public:
	Bulk();
	~Bulk();
	void displayInfo() const;


};






#endif // !BULK_H
