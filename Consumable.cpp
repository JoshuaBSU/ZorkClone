#include "Consumable.h"



Consumable::Consumable(std::string name, int value, std::string effect, int potency)
{
	this->name = name;
	this->value = value;

	this->effect = effect;
	this->potency = potency;

	this->consumable = true;
	this->equipable = false;
}

Consumable::~Consumable()
{
}

std::string Consumable::getEffect()
{
	return this->effect;
}

int Consumable::getPotency()
{
	return this->potency;
}