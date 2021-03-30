#include "Skeleton.h"



Skeleton::Skeleton()
{
	//attributes
	this->aDexterity = 2;
	this->aStrength = 2;

	//health
	this->maxHealth = 4;
	this->currHealth = maxHealth;

	//is it undead?
	this->undead = true;
}


Skeleton::~Skeleton()
{
}
