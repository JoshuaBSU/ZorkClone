#include "Human.h"

Human::Human()
{
	//attributes
	this->aDexterity = 5;
	this->aStrength = 5;

	//health
	this->maxHealth = 8;
	this->currHealth = maxHealth;

	//is it undead?
	this->undead = false;
}


Human::~Human()
{
}
