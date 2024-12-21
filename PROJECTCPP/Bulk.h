#ifndef BULK_H
#define BULK_H
#include "Goods.h"

class Bulk : public Goods
{
private:
	float volume;

public:
	Bulk(float volume = 0.0f, float weight = 0.0f, const std::string& name = "Unknown");
	~Bulk();
	void setVolume(float volume);
	float getVolume() const;
	std::string toString() const;
};






#endif // !BULK_H
