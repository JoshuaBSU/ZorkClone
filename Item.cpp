#include "Item.h"

Item::Item()
{
	// by default, items do not unlock any doors
	this->lockID = -1;
}

Item::~Item()
{
}

void Item::setDescription(std::string flavortext)
{
	this->description = flavortext;
}

std::string Item::getDescription()
{
	return this->description;
}

std::string Item::getName()
{
	return this->name;
}

int Item::getValue()
{
	return this->value;
}

bool Item::getEdibility()
{
	return this->consumable;
}

bool Item::getEquipable()
{
	return this->equipable;
}
std::string Item::getEquipCat()
{
	return this->equipCat;
}

//make it so this item unlocks a specific door
void Item::setLockID(int lock)
{
	this->lockID = lock;
}
int Item::getLockID()
{
	return this->lockID;
}