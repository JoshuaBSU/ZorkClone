#include "Orc.h"



Orc::Orc()
{
	//attributes
	this->aDexterity = 8;
	this->aStrength = 8;

	//health
	this->maxHealth = 16;
	this->currHealth = maxHealth;

	//is it undead?
	this->undead = false;
}


Orc::~Orc()
{
}
