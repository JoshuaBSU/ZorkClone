#include "Spell.h"

Spell::Spell(std::string name, std::string effect, int potency, int manaCost)
{
	this->name = name;
	this->effect = effect;
	this->potency = potency;
	this->manaCost = manaCost;
}

Spell::~Spell()
{
}

std::string Spell::getName()
{
	return this->name;
}
std::string Spell::getEffect()
{
	return this->effect;
}
int Spell::getPotency()
{
	return this->potency;
}
int Spell::getManaCost()
{
	return this->manaCost;
}