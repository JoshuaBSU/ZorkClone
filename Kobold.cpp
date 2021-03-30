#include "Kobold.h"



Kobold::Kobold()
{
	//attributes
	this->aDexterity = 4;
	this->aStrength = 4;

	//health
	this->maxHealth = 6;
	this->currHealth = maxHealth;

	//is it undead?
	this->undead = false;
}


Kobold::~Kobold()
{
}
