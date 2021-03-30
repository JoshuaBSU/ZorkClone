#pragma once
#include "Item.h"
class Consumable :
	public Item
{
public:
	Consumable(std::string name, int value, std::string effect, int potency);
	~Consumable();

	std::string getEffect();
	int getPotency();

private:
	std::string effect;
	int potency;
};

