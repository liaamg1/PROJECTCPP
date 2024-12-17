#ifndef BULK_H
#define BULK_H
#include "Goods.h"

class Bulk : public Goods
{
private:
	float volume;

public:
	Bulk(float volume = 0.0f, float weight, const std::string& type, const std::string& name);
	~Bulk();
	void setVolume(float volume);
	float getVolume() const override;
	std::string toString() const;
};






#endif // !BULK_H
