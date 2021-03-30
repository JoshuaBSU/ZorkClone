#include "VampireLord.h"



VampireLord::VampireLord(std::string name, Room* room)
{
	this->name = name;
	this->currentRoom = room;

	this->xpVal = 100;
	this->gold = 500;

	//default skills
	this->sFighting = 6;
	this->sShooting = 2;

	this->enemyType = "vampire lord";

	//attributes determined by parent class (Vampire)
	//health determined by parent class (Vampire)
}


VampireLord::~VampireLord()
{
}
