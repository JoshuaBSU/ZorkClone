#pragma once
#include "Item.h"
class Weapon :
	public Item
{
public:
	Weapon(std::string name, int value, int damage, bool type);
	~Weapon();

	bool getType();
	int getDamage();

private:
	//0=melee, 1=ranged
	bool type;

	int damage;
};

