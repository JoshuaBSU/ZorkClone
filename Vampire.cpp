#include "Vampire.h"



Vampire::Vampire()
{
	//attributes
	this->aDexterity = 7;
	this->aStrength = 7;

	//health
	this->maxHealth = 20;
	this->currHealth = maxHealth;

	//is it undead?
	this->undead = true;
}


Vampire::~Vampire()
{
}
