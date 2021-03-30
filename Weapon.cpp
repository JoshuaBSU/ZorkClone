#include "Weapon.h"



Weapon::Weapon(std::string name, int value, int damage, bool type)
{
	this->name = name;
	this->value = value;
	this->damage = damage;
	this->consumable = false;

	this->equipable = true;
	this->equipCat = "weapon";

	//0=melee, 1=ranged
	this->type = type;

}


Weapon::~Weapon()
{
}

bool Weapon::getType() {
	return this->type;
}

int Weapon::getDamage() {
	return this->damage;
}