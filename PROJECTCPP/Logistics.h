#ifndef INTERN_LOGISTIK_H
#define INTERN_LOGISTIK_H
#include "Goods.h"

class Logistics
{
public:
	Logistics();
	~Logistics();
private:
	Goods** Goods;
	int currentNrOfGoods;
};
#endif // !INTERN_LOGISTIK_H

